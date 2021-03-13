#include <algorithm>
#include <iostream>

#include <glm/gtc/matrix_access.hpp>

#include "tiling.hpp"

using namespace std;
using namespace csk;

// Suck in all the data arrays instead of trying to declare them
// inline.
namespace csk {
#include "tiling_arraydecl.inc"
};

IsohedralTiling::IsohedralTiling( TilingType ihtype )
{
	reset( ihtype );
}

void IsohedralTiling::reset( TilingType ihtype )
{
	tiling_type = ihtype;
	ttd = &tiling_type_data[ ihtype ];

	num_params = ttd->num_params;
	edge_shape_ids = ttd->edge_shape_ids;
	edge_shapes = ttd->edge_shapes;
	edge_shape_orientations = ttd->edge_orientations;
	aspect_xform_coefficients = ttd->aspect_xform_coeffs;
	translation_vector_coefficients = ttd->translation_vector_coeffs;
	tiling_vertex_coefficients = ttd->tiling_vertex_coeffs;
	colouring = ttd->colouring;

	setParameters( ttd->default_params );
}

IsohedralTiling::~IsohedralTiling()
{}

TilingType IsohedralTiling::getTilingType() const
{
	return tiling_type;
}

U8 IsohedralTiling::numParameters() const
{
	return num_params;
}

void IsohedralTiling::setParameters( const double *params )
{
	std::copy( params, params + num_params, parameters );
	recompute();
}

void IsohedralTiling::getParameters( double *params ) const
{
	std::copy( parameters, parameters + num_params, params );
}

U8 IsohedralTiling::numEdgeShapes() const
{
	return ttd->num_edge_shapes;
}

EdgeShape IsohedralTiling::getEdgeShape( EdgeID idx ) const
{
	return edge_shapes[ idx ];
}

U8 IsohedralTiling::numVertices() const
{
	return ttd->num_vertices;
}

const glm::dvec2& IsohedralTiling::getVertex( U8 idx ) const
{
	return verts[ idx ];
}

U8 IsohedralTiling::numAspects() const
{
	return ttd->num_aspects;
}

const glm::dmat3& IsohedralTiling::getAspectTransform( U8 idx ) const
{
	return aspects[ idx ];
}

FillAlgorithm IsohedralTiling::fillRegion( 
	double xmin, double ymin, double xmax, double ymax, bool dbg ) const
{
	return FillAlgorithm( *this, 
		glm::dvec2( xmin, ymin ), 
		glm::dvec2( xmax, ymin ), 
		glm::dvec2( xmax, ymax ), 
		glm::dvec2( xmin, ymax ), dbg );
}

FillAlgorithm IsohedralTiling::fillRegion( 
	const glm::dvec2& A, const glm::dvec2& B, 
	const glm::dvec2& C, const glm::dvec2& D, bool dbg ) const
{
	return FillAlgorithm( *this, A, B, C, D, dbg );
}

U8 IsohedralTiling::getColour( int t1, int t2, U8 aspect ) const
{
	U8 nc = colouring[18];

	int mt1 = t1 % nc;
	if( mt1 < 0 ) {
		mt1 += nc;
	}
	int mt2 = t2 % nc;
	if( mt2 < 0 ) {
		mt2 += nc;
	}
	U8 col = colouring[aspect];

	for( int idx = 0; idx < mt1; ++idx ) {
		col = colouring[12+col];
	}
	for( int idx = 0; idx < mt2; ++idx ) {
		col = colouring[15+col];
	}

	return col;
}

static inline double ddot(
	const double *coeffs, const double *params, U8 np )
{
	double total = 0.0;
	U8 idx;
	for( idx = 0; idx < np; ++idx ) {
		total += coeffs[idx] * params[idx];
	}
	// Affine term.
	total += coeffs[idx];
	return total;
}

static void fillMatrix( 
	const double *coeffs, const double *params, U8 np, glm::dmat3& M )
{
	for( U8 row = 0; row < 2; ++row ) {
		for( U8 col = 0; col < 3; ++col ) {
			M[col][row] = ddot( coeffs, params, np );
			coeffs += (np+1);
		}
	}
	M[0][2] = 0.0;
	M[1][2] = 0.0;
	M[2][2] = 1.0;
}

static void fillVector(
	const double *coeffs, const double *params, U8 np, glm::dvec2& v )
{
	v.x = ddot( coeffs, params, np );
	v.y = ddot( coeffs + (np+1), params, np );
}

static inline glm::dmat3 match( const glm::dvec2& p, const glm::dvec2& q )
{
	return glm::dmat3( 
		q.x - p.x, q.y - p.y, 0.0,
		p.y - q.y, q.x - p.x, 0.0,
		p.x, p.y, 1.0 );
}

static const glm::dmat3 M_orients[4] = {
	glm::dmat3( 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 ),   // IDENTITY
	glm::dmat3( -1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0 ), // ROT
	glm::dmat3( -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 ),  // FLIP
	glm::dmat3( 1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0 ),  // ROFL
};

void IsohedralTiling::recompute()
{
	U8 ntv = numVertices();

	// Recompute tiling vertex locations.
	const double *data = tiling_vertex_coefficients;
	for( U8 idx = 0; idx < ntv; ++idx ) {
		fillVector( data, parameters, num_params, verts[idx] );
		data += 2*(num_params+1);
	}

	// Recompute edge transforms and reversals from orientation information.
	for( U8 idx = 0; idx < ntv; ++idx ) {
		bool fl = edge_shape_orientations[ 2*idx ];
		bool ro = edge_shape_orientations[ 2*idx+1 ];
		reversals[idx] = (fl != ro);
		edges[idx] = match( verts[idx], verts[(idx+1)%ntv] ) 
			* M_orients[2*fl+ro];
	}

	// Recompute aspect xforms.
	data = aspect_xform_coefficients;
	U8 sz = numAspects();
	for( U8 idx = 0; idx < sz; ++idx ) {
		fillMatrix( data, parameters, num_params, aspects[idx] );
		data += 6*(num_params+1);
	}

	// Recompute translation vectors.
	data = translation_vector_coefficients;
	fillVector( data, parameters, num_params, t1 );
	fillVector( data + 2*(num_params+1), parameters, num_params, t2 );
}

void FillRegionIterator::dbg() const
{
	if( done ) {
		cerr << "[done]" << endl;
	} else {
		cerr << "[call_idx = " << call_idx << "; "
			 << "x = " << x << "; "
			 << "y = " << y << "; "
			 << "xlo = " << xlo << "; "
			 << "xhi = " << xhi << "; "
			 << "asp = " << asp << "]" << endl;
	}
}

bool FillRegionIterator::operator ==( const FillRegionIterator& other ) const
{
	if( &algo != &other.algo ) {
		return false;
	}
	if( done != other.done ) {
		return false;
	}
	if( done ) {
		return true;
	}

	return (call_idx == other.call_idx) 
		&& (fabs( x - other.x ) < 1e-7)
		&& (fabs( y - other.y ) < 1e-7)
		&& (asp == other.asp);
}

void FillRegionIterator::inc()
{
	++asp;
	if( asp < algo.tiling.numAspects() ) {
		return;
	}

	asp = 0;
	x = x + 1.0;
	if( x < (xhi + 1e-7) ) {
		return;
	}

	xlo += algo.data[call_idx].dxlo;
	xhi += algo.data[call_idx].dxhi;
	y = y + 1.0;
	x = floor( xlo );
	/*
	if( y < algo.data[call_idx].ymax ) {
		return;
	}
	*/
	if( floor(y) < floor(algo.data[call_idx].ymax) ) {
		return;
	}

	++call_idx;
	if( call_idx < algo.num_calls ) {
		xlo = algo.data[call_idx].xlo;
		xhi = algo.data[call_idx].xhi;
		y = std::max( y, floor( algo.data[call_idx].ymin ) );
		x = floor( algo.data[call_idx].xlo );
		return;
	}

	done = true;
}

FillRegionIterator::FillRegionIterator( const FillAlgorithm& alg )
	: algo( alg )
	, done( true )
{}

FillRegionIterator::FillRegionIterator( const FillAlgorithm& alg, 
		double xx, double yy, double xxlo, double xxhi )
	: algo( alg )
	, done( false )
	, call_idx( 0 )
	, x( xx )
	, y( yy )
	, xlo( xxlo )
	, xhi( xxhi )
	, asp( 0 )
{}

static glm::dvec2 sampleAtHeight( 
	const glm::dvec2& P, const glm::dvec2& Q, double y )
{
	double t = (y-P.y)/(Q.y-P.y);
	return glm::dvec2( (1.0-t)*P.x + t*Q.x, y );
}

void FillAlgorithm::doFill( 
	const glm::dvec2& A, const glm::dvec2& B,
	const glm::dvec2& C, const glm::dvec2& D, bool do_top )
{
	data[num_calls].xlo = A.x;
	data[num_calls].dxlo = (D.x-A.x)/(D.y-A.y);
	data[num_calls].xhi = B.x;
	data[num_calls].dxhi = (C.x-B.x)/(C.y-B.y);
	data[num_calls].ymin = A.y;
	data[num_calls].ymax = C.y;
	if( do_top ) {
		data[num_calls].ymax += 1.0;
	}

	if( debug ) {
		cerr << "Fill[" << num_calls << "]:" << endl;
		cerr << "\tA = " << A.x << ", " << A.y << endl;
		cerr << "\tB = " << B.x << ", " << B.y << endl;
		cerr << "\tC = " << C.x << ", " << C.y << endl;
		cerr << "\tD = " << D.x << ", " << D.y << endl;
		cerr << "\txlo = " << data[num_calls].xlo << endl;
		cerr << "\tdxlo = " << data[num_calls].dxlo << endl;
		cerr << "\txhi = " << data[num_calls].xhi << endl;
		cerr << "\tdxhi = " << data[num_calls].dxhi << endl;
		cerr << "\tymin = " << data[num_calls].ymin << endl;
		cerr << "\tymax = " << data[num_calls].ymax << endl;
	}

	++num_calls;
}

void FillAlgorithm::fillFixX( 
	const glm::dvec2& A, const glm::dvec2& B,
	const glm::dvec2& C, const glm::dvec2& D, bool do_top )
{
	if( A.x > B.x ) {
		doFill( B, A, D, C, do_top );
	} else {
		doFill( A, B, C, D, do_top );
	}
}
	
void FillAlgorithm::fillFixY(
	const glm::dvec2& A, const glm::dvec2& B,
	const glm::dvec2& C, const glm::dvec2& D, bool do_top )
{
	if( A.y > C.y ) {
		doFill( C, D, A, B, do_top );
	} else {
		doFill( A, B, C, D, do_top );
	}
}

FillAlgorithm::FillAlgorithm( const IsohedralTiling &t, 
		const glm::dvec2& A, const glm::dvec2& B, 
		const glm::dvec2& C, const glm::dvec2& D, bool dbg )
	: tiling( t )
	, num_calls( 0 )
	, debug( dbg )
{
	const glm::dvec2& t1 = tiling.getT1();
	const glm::dvec2& t2 = tiling.getT2();

	double det = 1.0 / (t1.x*t2.y-t2.x*t1.y);

	glm::dmat2 Mbc( t2.y * det, -t1.y * det, -t2.x * det, t1.x * det );

	glm::vec2 pts[4] = {
		Mbc * glm::dvec2( A ),
		Mbc * glm::dvec2( B ),
		Mbc * glm::dvec2( C ),
		Mbc * glm::dvec2( D )
	};

	if( det < 0.0 ) {
		swap( pts[1], pts[3] );
	}

	if( debug ) {
		cerr << "pts[0] = " << pts[0].x << ", " << pts[0].y << endl;
		cerr << "pts[1] = " << pts[1].x << ", " << pts[1].y << endl;
		cerr << "pts[2] = " << pts[2].x << ", " << pts[2].y << endl;
		cerr << "pts[3] = " << pts[3].x << ", " << pts[3].y << endl;
	}

	if( fabs( pts[0].y - pts[1].y ) < 1e-7 ) {
		fillFixY( pts[0], pts[1], pts[2], pts[3], true );
	} else if( fabs( pts[1].y - pts[2].y ) < 1e-7 ) {
		fillFixY( pts[1], pts[2], pts[3], pts[0], true );
	} else {
		size_t lowest = 0;
		for( size_t idx = 1; idx < 4; ++idx ) {
			if( pts[idx].y < pts[lowest].y ) {
				lowest = idx;
			}
		}

		glm::dvec2 bottom = pts[lowest];
		glm::dvec2 left = pts[(lowest+1)%4];
		glm::dvec2 top = pts[(lowest+2)%4];
		glm::dvec2 right = pts[(lowest+3)%4];

		if( debug ) {
			cerr << "bottom = " << bottom.x << ", " << bottom.y << endl;
			cerr << "left = " << left.x << ", " << left.y << endl;
			cerr << "top = " << top.x << ", " << top.y << endl;
			cerr << "right = " << right.x << ", " << right.y << endl;
		}

		if( left.x > right.x ) {
			swap( left, right );
		}

/*
		if( fabs( left.y - right.y ) < 1e-7 ) {
			fillFixX( bottom, bottom, right, left, false );
			fillFixX( left, right, top, top, true );
		} else
	*/	
		if( left.y < right.y ) {
			glm::vec2 r1 = sampleAtHeight( bottom, right, left.y );
			glm::vec2 l2 = sampleAtHeight( left, top, right.y );
			fillFixX( bottom, bottom, r1, left, false );
			fillFixX( left, r1, right, l2, false );
			fillFixX( l2, right, top, top, true );
		} else {
			glm::vec2 l1 = sampleAtHeight( bottom, left, right.y );
			glm::vec2 r2 = sampleAtHeight( right, top, left.y );
			fillFixX( bottom, bottom, right, l1, false );
			fillFixX( l1, right, r2, left, false );
			fillFixX( left, r2, top, top, true );
		}
	}
}

FillRegionIterator FillAlgorithm::begin() const
{
	return FillRegionIterator( *this, 
		floor( data[0].xlo ), floor( data[0].ymin ), data[0].xlo, data[0].xhi );
}

FillRegionIterator FillAlgorithm::end() const
{
	return FillRegionIterator( *this );
}

const static glm::dmat3 TSPI_U[] = {
	glm::dmat3( 0.5, 0.0, 0.0,  0.0, 0.5, 0.0,  0.0, 0.0, 1.0 ),
	glm::dmat3( -0.5, 0.0, 0.0,  0.0, 0.5, 0.0,  1.0, 0.0, 1.0 )
};

const static glm::dmat3 TSPI_S[] = {
	glm::dmat3( 0.5, 0.0, 0.0,  0.0, 0.5, 0.0,  0.0, 0.0, 1.0 ),
	glm::dmat3( -0.5, 0.0, 0.0,  0.0, -0.5, 0.0,  1.0, 0.0, 1.0 )
};

TileShapePartIterator::TileShapePartIterator( 
		const IsohedralTiling& t, size_t num )
	: tiling( t )
	, edge_num( num )
	, part( 0 )
{
	computeEdgeInfo();
}

void TileShapePartIterator::computeEdgeInfo()
{
	if( edge_num >= tiling.numVertices() ) {
		return;
	}

	edge_shape_id = tiling.edge_shape_ids[ edge_num ];
	shape = tiling.edge_shapes[ edge_shape_id ];

	if( shape == J || shape == I ) {
		xform = tiling.edges[ edge_num ];
		rev = tiling.reversals[ edge_num ];
	} else {
		rev = (part == 1);
		size_t index = part;
		if( tiling.reversals[ edge_num ] ) {
			index = 1 - index;
		}
		xform = tiling.edges[ edge_num ] * ((shape==U)?TSPI_U:TSPI_S)[index];
	}
}

TileShapePartIterator& TileShapePartIterator::operator++()
{
	if( part == 1 || shape == J || shape == I ) {
		part = 0;
		++edge_num;
	} else {
		++part;
	}

	computeEdgeInfo();
	return *this;
}

TileShapePartIterator TileShapePartIterator::operator++( int )
{
	TileShapePartIterator tsi( *this );
	++edge_num;
	return tsi;
}

}
