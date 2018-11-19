#include <algorithm>
#include <iostream>
#include <vector>

#ifdef __APPLE__
# define __gl_h_
# define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
# define GLFW_INCLUDE_GLCOREARB
#endif

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "nanovg.h"
#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

#include "tiling.hpp"

using namespace csk;
using namespace std;
using namespace glm;

static void calcEditorTransform();

// GLFW window stuff
int winWidth;
int winHeight;

// Which tiling we're displaying / editing
size_t the_type = 0;
double params[6];
IsohedralTiling tiling( 1 );
vector<vector<dvec2>> edges;
vector<dvec2> tile_shape;

// Location of the tile editor window
static const int editor_x = 20;
static const int editor_y = 280;
static const int editor_width = 250;
static const int editor_height = 300;
// transformation mapping the current tile into the editor window
dmat3 editor_transform;

// UI stuff: details of the vertex currently being manipulated
bool dragging = false;
size_t drag_edge_shape;
size_t drag_vertex;
mat3 drag_T;
bool u_constrain;

// More UI stuff: which features to enable / disasble
bool visualize_fill = false;
bool debug_fill = false;
bool show_editor = true;
bool show_translation = false;
double zoom = 1.0;

// A pleasing colour scheme
// color.adobe.com/Copy-of-C%C3%B3pia-de-Neutral-Blue-color-theme-11507885/
static const NVGcolor COLS[] = {
	nvgRGB( 25, 52, 65 ),
	nvgRGB( 62, 96, 111 ),
	nvgRGB( 145, 170, 157 ),
	nvgRGB( 209, 219, 189 ),
	nvgRGB( 252, 255, 245 ),
	nvgRGB( 219, 188, 209 )
};

// Compute and store the outline of the tile for drawing repeatedly.
static void cacheTileShape()
{
	tile_shape.clear();

	for( auto i : tiling.parts() ) {
		const vector<dvec2>& ej = edges[i->getId()];

		int cur = i->isReversed() ? (ej.size() - 2) : 1;
		int inc = i->isReversed() ? -1 : 1; 

		for( size_t idx = 0; idx < ej.size() - 1; ++idx ) {
			tile_shape.push_back( i->getTransform() * dvec3( ej[cur], 1.0 ) );
			cur += inc;
		}
	}
}

// Change the tiling type and generate default edges for a prototile of
// that type.
static void setTilingType()
{
	tiling.reset( tiling_types[the_type] );
	tiling.getParameters( params );

	edges.clear();
	for( size_t idx = 0; idx < tiling.numEdgeShapes(); ++idx ) {
		vector<dvec2> ej;
		ej.push_back( dvec2( 0.0, 0.0 ) );
		ej.push_back( dvec2( 1.0, 0.0 ) );
		edges.push_back( ej );
	}

	cacheTileShape();
	calcEditorTransform();
}

static void nextTilingType()
{
	if( the_type < 80 ) {
		the_type++;
		setTilingType();
	}
}

static void prevTilingType()
{
	if( the_type > 0 ) {
		the_type--;
		setTilingType();
	}
}

static dmat3 centreRect( double xmin, double ymin, double xmax, double ymax )
{
	double sc = std::min( 
		(winWidth-50)/(xmax-xmin), (winHeight-50)/(ymax-ymin) );
	return dmat3( 1, 0, 0, 0, 1, 0, winWidth/2.0, winHeight/2.0, 1.0 )
		* dmat3( sc, 0, 0, 0, -sc, 0, 0, 0, 1 )
		* dmat3( 1, 0, 0, 0, 1, 0, -0.5*(xmin+xmax), -0.5*(ymin+ymax), 1 );
}

inline static void tmoveto( NVGcontext *vg, const dmat3& T, double x, double y )
{
	dvec2 P = T * dvec3( x, y, 1.0 );
	nvgMoveTo( vg, P.x, P.y );
}

inline static void tlineto( NVGcontext *vg, const dmat3& T, double x, double y )
{
	dvec2 P = T * dvec3( x, y, 1.0 );
	nvgLineTo( vg, P.x, P.y );
}

// Display a quick visualization of the region filling algorithm -- helpful
// for debugging.
void vizTiling( NVGcontext *vg, bool dbg = false )
{
	tiling.setParameters( params );

	if( dbg ) {
		cerr << "Tiling polygon" << endl;
		for( size_t idx = 0; idx < tiling.numVertices(); ++idx ) {
			const dvec2& p = tiling.getVertex( idx );
			cerr << "\t" << p.x << " " << p.y << endl;
		}
	}

	const glm::dvec2& t1 = tiling.getT1();
	const glm::dvec2& t2 = tiling.getT2();

    double det = 1.0 / (t1.x*t2.y-t2.x*t1.y);

	double l = -3.0;
	double r = 3.0;
	double b = -3.0;
	double t = 3.0;

    if( det < 0.0 ) {
        swap( t, b );
    }

    glm::dmat2 B( t2.y * det, -t1.y * det, -t2.x * det, t1.x * det );

    glm::dvec2 pts[4] = {
        B * glm::dvec2( l, b ),
        B * glm::dvec2( r, b ),
        B * glm::dvec2( r, t ),
        B * glm::dvec2( l, t ) };

	double xmin = pts[0].x;
	double xmax = pts[0].x;
	double ymin = pts[0].y;
	double ymax = pts[0].y;
	for( size_t idx = 1; idx < 4; ++idx ) {
		xmin = std::min( xmin, pts[idx].x );
		xmax = std::max( xmax, pts[idx].x );
		ymin = std::min( ymin, pts[idx].y );
		ymax = std::max( ymax, pts[idx].y );
	}

	dmat3 M = centreRect( xmin-2.0, ymin-2.0, xmax+2.0, ymax+2.0 );

	FillAlgorithm alg = tiling.fillRegion( -3.0, -3.0, 3.0, 3.0, dbg );
	for( auto i : alg ) {
		if( i->getAspect() != 0 ) {
			continue;
		}
		if( dbg ) {
			i->dbg();
		}
		// dmat3 T = M * i->getTransform();
		int t1 = i->getT1();
		int t2 = i->getT2();

		nvgBeginPath( vg );
		tmoveto( vg, M, t1, t2 );
		tlineto( vg, M, t1+1, t2 );
		tlineto( vg, M, t1+1, t2+1 );
		tlineto( vg, M, t1, t2+1 );
		nvgClosePath( vg );
		nvgFillColor( vg, nvgRGBAf( 0.2, 0.2, 0.2, 0.3 ) );
		nvgFill( vg );
		nvgStrokeColor( vg, nvgRGBf( 1.0, 0.6, 0.4 ) );
		nvgStroke( vg );
	}

	nvgStrokeColor( vg, nvgRGBf( 0.0, 1.0, 0.0 ) );
	nvgBeginPath( vg );
	tmoveto( vg, M, pts[0].x, pts[0].y );
	tlineto( vg, M, pts[1].x, pts[1].y );
	tlineto( vg, M, pts[2].x, pts[2].y );
	tlineto( vg, M, pts[3].x, pts[3].y );
	nvgClosePath( vg );
	nvgStroke( vg );

	nvgStrokeColor( vg, nvgRGBf( 1.0, 0.0, 0.0 ) );
	nvgBeginPath( vg );
	tmoveto( vg, M, 0, 0 );
	tlineto( vg, M, 1, 0 );
	nvgStroke( vg );
	nvgStrokeColor( vg, nvgRGBf( 0.0, 0.0, 1.0 ) );
	nvgBeginPath( vg );
	tmoveto( vg, M, 0, 0 );
	tlineto( vg, M, 0, 1 );
	nvgStroke( vg );
}

void drawTiling( NVGcontext *vg )
{
	double asp = double(winWidth) / double(winHeight);
	double h = 6.0 * zoom;
	double w = asp * h * zoom;
	double sc = winHeight / (2*h);
	dmat3 M = dmat3( 1, 0, 0, 0, 1, 0, winWidth/2.0, winHeight/2.0, 1.0 )
		* dmat3( sc, 0, 0, 0, -sc, 0, 0, 0, 1 );

	nvgStrokeWidth( vg, 1.0 );

	for( auto i : tiling.fillRegion( -w-2.0, -h-2.0, w+2.0, h+2.0 ) ) {
		dmat3 TT = i->getTransform();
		dmat3 T = M * TT;
		dvec2 P;
		
		/*
		// Check whether any vertex of the tile overlaps the window.
		// Probably not worth the computational effort -- easier just to
		// draw (and then clip) the tile.
		bool sect = false;

		for( auto v : tile_shape ) {
			P =  T * dvec3( v, 1.0 );
			if( (P.x>=0) && (P.x<=winWidth) && (P.y>=0) && (P.y<=winHeight) ) {
				sect = true;
				break;
			}
		}

		if( !sect ) {
			continue;
		}
		*/

		bool at_start = true;
		nvgBeginPath( vg );
		for( auto v : tile_shape ) {
			P = T * dvec3( v, 1.0 );
			if( at_start ) {
				at_start = false;
				nvgMoveTo( vg, P.x, P.y );
			} else {
				nvgLineTo( vg, P.x, P.y );
			}
		}
		nvgClosePath( vg );

		int t1 = i->getT1();
		int t2 = i->getT2();

		if( show_translation && (t1==0) && (t2==0) ) {
			nvgFillColor( vg, nvgRGB( 255, 0, 0 ) );
		} else {
			U8 col = tiling.getColour( t1, t2, i->getAspect() );
			nvgFillColor( vg, COLS[col+1] );
		}
		nvgFill( vg );
		nvgStrokeColor( vg, COLS[0] );
		nvgStroke( vg );
	}

	if( show_translation ) {
		const dvec2& T1 = tiling.getT1();
		const dvec2& T2 = tiling.getT2();

		nvgBeginPath( vg );
		tmoveto( vg, M, 0.0, 0.0 );
		tlineto( vg, M, T1.x, T1.y );
		nvgStrokeColor( vg, nvgRGB( 0, 255, 0 ) );
		nvgStroke( vg );
		nvgBeginPath( vg );
		tmoveto( vg, M, 0.0, 0.0 );
		tlineto( vg, M, T2.x, T2.y );
		nvgStrokeColor( vg, nvgRGB( 0, 0, 255 ) );
		nvgStroke( vg );
	}
}

static void calcEditorTransform()
{
	double xmin = 1e7;
	double xmax = -1e7;
	double ymin = 1e7;
	double ymax = -1e7;

	for( auto v : tile_shape ) {
		xmin = std::min( xmin, v.x );
		xmax = std::max( xmax, v.x );
		ymin = std::min( ymin, v.y );
		ymax = std::max( ymax, v.y );
	}
	
	double sc = std::min( 
		(editor_width-50) / (xmax-xmin), (editor_height-50) / (ymax-ymin) );

	editor_transform = 
		dmat3( 1, 0, 0, 0, 1, 0,
			editor_x + 0.5*editor_width, editor_y + 0.5*editor_height, 1.0 )
		* dmat3( sc, 0, 0, 0, -sc, 0, 0, 0, 1 )
		* dmat3( 1, 0, 0, 0, 1, 0, -0.5*(xmin+xmax), -0.5*(ymin+ymax), 1 );
}

static double distToSeg( const dvec2& P, const dvec2& A, const dvec2& B )
{
	dvec2 qmp = B - A;
	double t = dot( P - A, qmp ) / length2( qmp );
	if( (t >= 0.0) && (t <= 1.0) ) {
		dvec2 O = A + t * qmp;
		return distance( O, P ); 
	} else if( t < 0.0 ) {
		return distance( P, A );
	} else {
		return distance( P, B );
	}
}

// Click on an editable vertex to start moving it.  Shift-click to
// delete a vertex.  Click on an edge to generate a vertex there.
static bool hitTestEditor( const dvec2& mpt, bool del = false )
{
	dragging = false;

	if( !show_editor ) {
		return false;
	}

	if( (mpt.x < editor_x) || (mpt.x > (editor_x + editor_width)) ) {
		return false;
	}

	if( (mpt.y < editor_y) || (mpt.y > (editor_y + editor_height)) ) {
		return false;
	}
		
	for( auto i : tiling.parts() ) {
		EdgeShape shp = i->getShape();

		if( shp == I ) {
			continue;
		}

		U8 id = i->getId();
		vector<dvec2>& ej = edges[id];
		dmat3 T = editor_transform * i->getTransform();

		dvec2 P = T * dvec3( ej[0], 1.0 );
		for( size_t idx = 1; idx < ej.size(); ++idx ) {
			dvec2 Q = T * dvec3( ej[idx], 1.0 );
			// Check vertex
			if( distance2( Q, mpt ) < 49 ) {
				u_constrain = false;
				if( !del && (idx == (ej.size()-1)) ) {
					if( (shp == U) && !i->isSecondPart() ) {
						u_constrain = true;
					} else {
						break;
					}
				}
				if( del ) {
					if( idx < (ej.size()-1) ) {
						ej.erase( ej.begin() + idx );
						cacheTileShape();
					}
					return false;
				} else {
					dragging = true;
					drag_edge_shape = id;
					drag_vertex = idx;
					drag_T = inverse( T );

					return true;
				}
			}

			if( del ) {
				continue;
			}
			// Check segment
			if( distToSeg( mpt, P, Q ) < 7.0 ) {
				dragging = true;
				drag_edge_shape = id;
				drag_vertex = idx;
				drag_T = inverse( T );

				auto i = ej.begin() + idx;
				ej.insert( i, drag_T * dvec3( mpt, 1.0 ) );
				cacheTileShape();
				return true;
			}
			
			P = Q;
		}
	}

	return false;
}

void drawEditor( NVGcontext *vg )
{
	nvgFillColor( vg, nvgRGBA( 252, 255, 254, 220 ) );
	nvgBeginPath( vg );
	nvgRect( vg, editor_x, editor_y, editor_width, editor_height );
	nvgFill( vg );

	// Clip to the editor window bounds.  (A rounded rect would be better,
	// but nanovg uses a simple scissor rectangle, so this will do fine.)
	nvgScissor( vg, editor_x, editor_y, editor_width, editor_height );
	bool at_start = true;
	nvgStrokeWidth( vg, 2.0 );
	nvgStrokeColor( vg, COLS[0] );
	nvgFillColor( vg, COLS[3] );

	// Draw the interior of the tile.
	nvgBeginPath( vg );
	for( auto v : tile_shape ) {
		if( at_start ) {
			at_start = false;
			tmoveto( vg, editor_transform, v.x, v.y );
		} else {
			tlineto( vg, editor_transform, v.x, v.y );
		}
	}
	nvgClosePath( vg );
	nvgFill( vg );

	// Draw the edges of the tile
	for( auto i : tiling.parts() ) {
		if( i->getShape() == I ) {
			// Ghost I edges to show that they can't be edited.
			// (dashed lines would be better, but nanovg doesn't have them)
			nvgStrokeColor( vg, nvgRGB( 128, 128, 128 ) );
		} else {
			nvgStrokeColor( vg, nvgRGB( 0, 0, 0 ) );
		}

		const dmat3& T = editor_transform * i->getTransform();
		at_start = true;
		nvgBeginPath( vg );
		for( auto v : edges[i->getId()] ) {
			if( at_start ) {
				at_start = false;
				tmoveto( vg, T, v.x, v.y );
			} else {
				tlineto( vg, T, v.x, v.y );
			}
		}
		nvgStroke( vg );
	}

	nvgFillColor( vg, nvgRGB( 128, 128, 128 ) );

	// Draw the tiling vertices, which are not directly editable.
	for( auto v : tiling.vertices() ) {
		dvec2 pt = editor_transform * dvec3( v, 1.0 );
		nvgBeginPath( vg );
		nvgArc( vg, pt.x, pt.y, 5.0, 0.0, 2.0*M_PI, NVG_CCW );
		nvgFill( vg );
	}

	// Draw the editable vertices.
	for( auto i : tiling.parts() ) {
		EdgeShape shp = i->getShape();
		U8 id = i->getId();
		const vector<dvec2>& ej = edges[id];
		dmat3 T = editor_transform * i->getTransform();

		for( size_t idx = 1; idx < ej.size() - 1; ++idx ) {
			nvgFillColor( vg, nvgRGB( 0, 0, 0 ) );
			dvec2 pt = T * dvec3( ej[idx], 1.0 );
			nvgBeginPath( vg );
			nvgArc( vg, pt.x, pt.y, 5.0, 0.0, 2.0*M_PI, NVG_CCW );
			nvgFill( vg );
		}

		if( shp == I || shp == J ) {
			continue;
		}

		// Draw the central vertex of an S edge in a special colour 
		// (even though it's not editable, it's easier to manipulate the
		// rest of the edge of the centre is visible).  Draw the
		// central vertex of a U edge in yet another colour.
		if( !i->isSecondPart() ) {
			if( shp == U ) {
				nvgFillColor( vg, COLS[ 2 ] );
			} else {
				nvgFillColor( vg, COLS[ 5 ] );
			}
			dvec2 pt = T * dvec3( ej.back(), 1.0 );
			nvgBeginPath( vg );
			nvgArc( vg, pt.x, pt.y, 5.0, 0.0, 2.0*M_PI, NVG_CCW );
			nvgFill( vg );
		}
	}

	nvgResetScissor( vg );

	nvgStrokeWidth( vg, 3.0 );
	nvgStrokeColor( vg, nvgRGBA( 25, 52, 65, 220 ) );
	nvgBeginPath( vg );
	nvgRect( vg, editor_x, editor_y, editor_width, editor_height );
	nvgStroke( vg );
}

static void mouseMotion( GLFWwindow* window, double xpos, double ypos )
{
	if( dragging ) {
		dvec2 npt = drag_T * dvec3( xpos, ypos, 1.0 );
		if( u_constrain ) {
			npt.x = 1.0;
		}
			
		edges[drag_edge_shape][drag_vertex] = npt;
		cacheTileShape();
	}
}

static void mouse( GLFWwindow *window, int button, int action, int mods )
{
  if( button == GLFW_MOUSE_BUTTON_LEFT ) {
  	if( action == GLFW_PRESS ) {
		double xpos;
		double ypos;
		glfwGetCursorPos( window, &xpos, &ypos );
		hitTestEditor( dvec2( xpos, ypos ), mods & GLFW_MOD_SHIFT );
	} else if( action == GLFW_RELEASE ) {
		dragging = false;
	}
  }
}

static void key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	NVG_NOTUSED(scancode);
	NVG_NOTUSED(mods);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	} else if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		nextTilingType();
	} else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		prevTilingType();
	} else if (key == GLFW_KEY_V && action == GLFW_PRESS) {
		visualize_fill = !visualize_fill;
	} else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		debug_fill = true;
	} else if (key == GLFW_KEY_T && action == GLFW_PRESS) {
		show_translation = !show_translation;
	} 
}

static void error_callback( int error, const char *desc )
{
	cerr << "GLFW Error " << error << ": " << desc << endl;
}

int main()
{
	// Most of this code is adapted directly from the OpenGL3/GLFW example 
	// in the ImGui distribution.  Thanks!

	glfwSetErrorCallback( error_callback );
	if (!glfwInit()) {
		printf("Failed to init GLFW.");
		return -1;
	}

#if __APPLE__
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);          
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

	GLFWwindow *window = glfwCreateWindow( 
		1000, 600, "NanoVG", nullptr, nullptr );
	if( !window ) {
		cerr << "Could not create window." << endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent( window );
	glfwSwapInterval( 1 );

	if( gl3wInit() != 0 ) {
		cerr << "Could not initialize OpenGL loader." << endl;
		return 1;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplGlfw_InitForOpenGL( window, true );
	ImGui_ImplOpenGL3_Init( glsl_version );
	ImGui::StyleColorsDark();

	glfwSetKeyCallback( window, key );
	glfwSetMouseButtonCallback( window, mouse );
	glfwSetCursorPosCallback( window, mouseMotion );

	NVGcontext* vg = nvgCreateGL3(
		NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG );
	if( !vg ) {
		cerr << "Could not initialize nanovg." << endl;
		return 1;
	}

	setTilingType();

	while( !glfwWindowShouldClose( window ) ) {
		glfwPollEvents();

		// Draw the ImGui interface

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		static bool first_run( true );
		if( first_run ) {
			ImGui::SetNextWindowPos( ImVec2( 20, 20 ) );
			first_run = false;
		}
		
		ImGui::Begin( "Tiling Viewer" );

		if( ImGui::ArrowButton( "Prev", ImGuiDir_Left ) ) {
			prevTilingType();
		}
		ImGui::SameLine();
		ImGui::Text( "IH%02ld", size_t( tiling_types[ the_type ] ) );
		ImGui::SameLine();
		if( ImGui::ArrowButton( "Next", ImGuiDir_Right ) ) {
			nextTilingType();
		}

		ImGui::Checkbox( "Show editor", &show_editor );
		if( ImGui::Button( "Zoom in" ) ) {
			zoom = zoom * 0.9;
		}
		ImGui::SameLine();
		if( ImGui::Button( "Zoom out" ) ) {
			zoom = zoom / 0.9;
		}

		// ImGui::Checkbox( "Visualize fill", &visualize_fill );
		// ImGui::Checkbox( "Debug fill", &debug_fill );
		bool slid = false;
		for( size_t idx = 0; idx < tiling.numParameters(); ++idx ) {
			float fp = float( params[idx] );
			char buf[10];
			sprintf( buf, "v%ld", idx );
			bool s = ImGui::SliderFloat( buf, &fp, -2.0, 2.0 );
			slid = slid || s;
			params[idx] = fp;
		}

		if( ImGui::Button( "Quit" ) ) {
			glfwSetWindowShouldClose( window, GL_TRUE );
		}
		ImGui::End();
		ImGui::Render();

		int fbWidth, fbHeight;
		float pxRatio;
		glfwGetWindowSize( window, &winWidth, &winHeight );
		glfwGetFramebufferSize( window, &fbWidth, &fbHeight );
		pxRatio = (float)fbWidth / (float)winWidth;

		// Update and render
		glViewport( 0, 0, fbWidth, fbHeight );
		glClearColor( 252.0f/255.0f, 255.0f/255.0f, 245.0f/255.0f, 1.0f );
		glClear( 
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		// Draw the tiling and editor

		nvgBeginFrame(vg, winWidth, winHeight, pxRatio);

		tiling.setParameters( params );
		if( slid ) {
			calcEditorTransform();
			cacheTileShape();
		}

		nvgLineJoin( vg, NVG_ROUND );
		if( visualize_fill ) {
			vizTiling( vg, debug_fill );
			debug_fill = false;
		} else {
			drawTiling( vg );
		}

		if( show_editor ) {
			drawEditor( vg );
		}
		nvgEndFrame( vg );

		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

		glfwSwapBuffers(window);
	}

	nvgDeleteGL3( vg );
	glfwTerminate();
	return 0;
}
