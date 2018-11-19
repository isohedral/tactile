//
// A simple demonstration of creating, manipulating, and drawing an 
// isohedral tiling.  Generate a random tiling for each isohedral
// type and output a Postscript file displaying them (suitable for
// converting into PDF).  
//
// Note that the program might randomly generate tiles that
// self-intersect.  That's not a bug in the library, it's just a 
// bad choice of tiling vertex parameters and edge shapes.
//

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "tiling.hpp"

using namespace csk;
using namespace std;
using namespace glm;

// A pleasing colour scheme
// color.adobe.com/Copy-of-C%C3%B3pia-de-Neutral-Blue-color-theme-11507885/
static const int COLS[] = {
	145, 170, 157,
	209, 219, 189,
	252, 255, 245
};

random_device rd;
mt19937 gen( rd() );
uniform_real_distribution<> dis( 0.0, 1.0 );

static double zeta()
{
	return dis(gen);
}

static dmat3 centrePSRect( double xmin, double ymin, double xmax, double ymax )
{
	double sc = std::min( 6.5*72.0 / (xmax-xmin), 9.0*72.0 / (ymax-ymin) );
	return dmat3( 1, 0, 0, 0, 1, 0, 4.25*72.0, 5.5*72.0, 1.0 )
		* dmat3( sc, 0, 0, 0, sc, 0, 0, 0, 1 )
		* dmat3( 1, 0, 0, 0, 1, 0, -0.5*(xmin+xmax), -0.5*(ymin+ymax), 1 );
}

static void outShape( const vector<dvec2>& vec, const dmat3& M )
{
	dvec2 p = M * dvec3( vec.back(), 1.0 );
	cout << p.x << " " << p.y << " moveto" << endl;

	for( size_t idx = 0; idx < vec.size(); idx += 3 ) {
		dvec2 p1 = M * dvec3( vec[idx], 1.0 );
		dvec2 p2 = M * dvec3( vec[idx+1], 1.0 );
		dvec2 p3 = M * dvec3( vec[idx+2], 1.0 );

		cout << p1.x << " " << p1.y << " "
			 << p2.x << " " << p2.y << " "
			 << p3.x << " " << p3.y << " curveto" << endl;
	}

	cout << "closepath" << endl;
}

void drawTiling( TilingType num )
{
	// Construct a tiling of the given type.
	IsohedralTiling t( num );
	// Create an array to hold a copy of the tiling vertex parameters.
	double ps[ t.numParameters() ];
	// Now fill the array with the current values of the parameters,
	// which will be set to reasonable defaults when the tiling is
	// created.
	t.getParameters( ps );
	// Perturb the parameters a bit to get a novel tiling.
	for( size_t idx = 0; idx < t.numParameters(); ++idx ) {
		ps[idx] += zeta()*0.2 - 0.1;
	}
	// Now send those parameters back to the tiling.
	t.setParameters( ps );

	// Create a vector to hold some edge shapes.  The tiling tells you
	// how many distinct edge shapes you need, but doesn't know anything
	// about how those shapes might be represented.  It simply assumes
	// that each one will be a curve from (0,0) to (1,0).  The tiling
	// provides tools to let you map those curves into position around
	// the outline of a tile.  All the curves below have exactly four
	// control points, so using a vector is overkill; but it offers a 
	// more convenient starting point for experimentation with fancier
	// curves, so I'll keep it.
	vector<dvec2> edges[ t.numEdgeShapes() ];

	// Generate some random edge shapes.
	for( U8 idx = 0; idx < t.numEdgeShapes(); ++idx ) {
		vector<dvec2> ej;

		// Start by making a random Bezier segment.
		ej.push_back( dvec2( 0, 0 ) );
		ej.push_back( dvec2( zeta() * 0.75, zeta() * 0.6 - 0.3 ) );
		ej.push_back( 
			dvec2( zeta() * 0.75 + 0.25, zeta() * 0.6 - 0.3 ) );
		ej.push_back( dvec2( 1, 0 ) );

		// Now, depending on the edge shape class, enforce symmetry 
		// constraints on edges.
		switch( t.getEdgeShape( idx ) ) {
		case J: 
			break;
		case U:
			ej[2].x = 1.0 - ej[1].x;
			ej[2].y = ej[1].y;
			break;
		case S:
			ej[2].x = 1.0 - ej[1].x;
			ej[2].y = -ej[1].y;
			break;
		case I:
			ej[1].y = 0.0;
			ej[2].y = 0.0;
			break;
		}
		edges[idx] = ej;
	}

	// Use a vector to hold the control points of the final tile outline.
	vector<dvec2> shape;

	// Iterate over the edges of a single tile, asking the tiling to
	// tell you about the geometric information needed to transform 
	// the edge shapes into position.  Note that this iteration is over
	// whole tiling edges.  It's also to iterator over partial edges
	// (i.e., halves of U and S edges) using t.parts() instead of t.shape().
	for( auto i : t.shape() ) {
		// Get the relevant edge shape created above using i->getId().
		const vector<dvec2>& ed = edges[ i->getId() ];
		// Also get the transform that maps to the line joining consecutive
		// tiling vertices.
		const glm::dmat3& T = i->getTransform();

		// If i->isReversed() is true, we need to run the parameterization
		// of the path backwards.
		if( i->isReversed() ) {
			for( size_t idx = 1; idx < ed.size(); ++idx ) {
				shape.push_back( T * dvec3( ed[ed.size()-1-idx], 1.0 ) );
			}
		} else {
			for( size_t idx = 1; idx < ed.size(); ++idx ) {
				shape.push_back( T * dvec3( ed[idx], 1.0 ) );
			}
		}
	}

	dmat3 M = centrePSRect( -6.0, -6.0, 6.0, 6.0 );
	dvec2 p = M * dvec3( -6.0, -6.0, 1.0 );
	cout << p.x << " " << p.y << " moveto" << endl;
	p = M * dvec3( 6.0, -6.0, 1.0 );
	cout << p.x << " " << p.y << " lineto" << endl;
	p = M * dvec3( 6.0, 6.0, 1.0 );
	cout << p.x << " " << p.y << " lineto" << endl;
	p = M * dvec3( -6.0, 6.0, 1.0 );
	cout << p.x << " " << p.y << " lineto closepath clip newpath" << endl;

	// Ask the tiling to generate (approximately) enough tiles to
	// fill the bounding box below.  The bounding box is a bit bigger
	// than the box we actually want to display in the document, to
	// hopefully ensure that it completely covers that box.
	for( auto i : t.fillRegion( -8.0, -8.0, 8.0, 8.0 ) ) {
		// The region filling algorithm will give us a transform matrix
		// that takes a tile in default position to its location in the
		// tiling.
		dmat3 T = M * i->getTransform();
		// The tiling can also apply a default colouring algorithm to
		// suggest a tile colour label (just an integer).  All tilings
		// are 2-coloured or 3-coloured (and the colourings are not
		// necessarily "perfect colourings" in the mathematical sense).
		U8 col = t.getColour( i->getT1(), i->getT2(), i->getAspect() );

		// Now draw the transformed tile.
		outShape( shape, T );
		cout << "gsave" << endl;
		cout << (COLS[3*col]/255.0) << " " 
			 << (COLS[3*col+1]/255.0) << " " 
			 << (COLS[3*col+2]/255.0) << " setrgbcolor fill" << endl;
		cout << "grestore 0 setgray stroke newpath" << endl;
	}
	cout << "initclip" << endl;

	cout << "0 setgray 306 100 moveto (IH" << int(num) << ") cshow" << endl;
	cout << "showpage" << endl;
}

int main( int argc, char **argv )
{
	cout << "%!PS-Adobe-3.0" << endl << endl;
	cout << "/Helvetica findfont 24 scalefont setfont" << endl;
	cout << "/cshow { dup stringwidth pop -0.5 mul 0 rmoveto show } def"
		<< endl;

	// Use num_types and tiling_types to restrict to legal tiling types.
	for( size_t idx = 0; idx < num_types; ++idx ) {
		drawTiling( tiling_types[idx] );
	}

	cout << "%%EOF" << endl;

	return 0;
}
