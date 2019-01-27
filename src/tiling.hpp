#ifndef __TILING_HPP__
#define __TILING_HPP__

#include <glm/glm.hpp>

namespace csk {

typedef unsigned char U8;

typedef U8 TilingType;
typedef U8 EdgeID;

class IsohedralTiling;
class TileShapeIterator;
class TileShapePartIterator;
class FillRegionIterator;
class FillAlgorithm;
class TilingVertexProxy;

enum EdgeShape
{
	J, U, S, I
};

struct TilingTypeData {
	U8				num_params;
	U8				num_aspects;
	U8				num_vertices;
	U8				num_edge_shapes;

	const EdgeShape	*edge_shapes;
	const bool		*edge_orientations;
	const U8		*edge_shape_ids;
	const double	*default_params;
	const double	*tiling_vertex_coeffs;
	const double	*translation_vector_coeffs;
	const double	*aspect_xform_coeffs;
	const U8		*colouring;
};

const size_t num_types = 81;
extern const U8 tiling_types[81];

class TileShapeIterator
{
public:
	TileShapeIterator( const IsohedralTiling& t, size_t num );

	const glm::dmat3& getTransform() const;
	U8 getId() const;
	EdgeShape getShape() const;
	bool isReversed() const;

	bool operator ==( const TileShapeIterator& other ) const;
	bool operator !=( const TileShapeIterator& other ) const;
	const TileShapeIterator& operator *();
	const TileShapeIterator *operator->();
	TileShapeIterator& operator++();
	TileShapeIterator operator++( int );
	TileShapeIterator& operator--();
	TileShapeIterator operator--( int );

private:
	const IsohedralTiling& tiling;
	U8 edge_num;
};

class TileShapePartIterator
{
public:
	TileShapePartIterator( const IsohedralTiling& t, size_t num );

	const glm::dmat3& getTransform() const;
	U8 getId() const;
	EdgeShape getShape() const;
	bool isReversed() const;
	bool isSecondPart() const;

	bool operator ==( const TileShapePartIterator& other ) const;
	bool operator !=( const TileShapePartIterator& other ) const;
	const TileShapePartIterator& operator *();
	const TileShapePartIterator *operator->();
	TileShapePartIterator& operator++();
	TileShapePartIterator operator++( int );

private:
	void computeEdgeInfo();

	const IsohedralTiling& tiling;
	U8 edge_num;
	U8 part;

	glm::dmat3 xform;
	U8 edge_shape_id;
	bool rev;
	EdgeShape shape;
};

class TileShapeIteratorProxy
{
public:
	TileShapeIteratorProxy( const IsohedralTiling& t );

	TileShapeIterator begin();
	TileShapeIterator end();

	const IsohedralTiling& tiling;
};

class TilePartsIteratorProxy
{
public:
	TilePartsIteratorProxy( const IsohedralTiling& t );

	TileShapePartIterator begin();
	TileShapePartIterator end();

	const IsohedralTiling& tiling;
};

class TilingVertexProxy
{
public:
	TilingVertexProxy( const IsohedralTiling& t );

	const glm::dvec2 *begin() const;
	const glm::dvec2 *end() const;

	const IsohedralTiling& tiling;
};

class FillRegionIterator
{
	friend class FillAlgorithm;

public:
	glm::dmat3 getTransform() const;
	int getT1() const;
	int getT2() const;
	size_t getAspect() const;
	void dbg() const;

	bool operator ==( const FillRegionIterator& other ) const;
	bool operator !=( const FillRegionIterator& other ) const;
	const FillRegionIterator& operator *();
	const FillRegionIterator *operator->();
	FillRegionIterator& operator++();
	FillRegionIterator operator++( int );

private:
	FillRegionIterator( const FillAlgorithm& algo );
	FillRegionIterator( const FillAlgorithm& algo, 
		double x, double y, double xlo, double xhi );

	void inc();

	const FillAlgorithm&	algo;
	bool					done;
	size_t 					call_idx;
	double					x;
	double 					y;
	double 					xlo;
	double 					xhi;
	size_t					asp;
};

class FillAlgorithm
{
	friend class FillRegionIterator;

public:
	FillAlgorithm( const IsohedralTiling &t, 
		const glm::dvec2& A, const glm::dvec2& B, 
		const glm::dvec2& C, const glm::dvec2& D, bool dbg = false );

	FillRegionIterator begin() const;
	FillRegionIterator end() const;

private:
	void doFill( const glm::dvec2& A, const glm::dvec2& B,
		const glm::dvec2& C, const glm::dvec2& D, bool do_top );
	void fillFixX( const glm::dvec2& A, const glm::dvec2& B,
		const glm::dvec2& C, const glm::dvec2& D, bool do_top );
	void fillFixY( const glm::dvec2& A, const glm::dvec2& B,
		const glm::dvec2& C, const glm::dvec2& D, bool do_top );

	const IsohedralTiling&	tiling;
	size_t num_calls;
	bool debug;

	struct {
		double ymin;
		double ymax;
		double xlo;
		double xhi;
		double dxlo;
		double dxhi;
	} data[3];
};

class IsohedralTiling
{
	friend class TileShapeIterator;
	friend class TileShapePartIterator;
	friend class TilingVertexProxy;

public:
	IsohedralTiling( TilingType ihtype );
	~IsohedralTiling();

	void reset( TilingType ihtype );

	TilingType getTilingType() const;

	U8 numParameters() const;
	void setParameters( const double *params );
	void getParameters( double *params ) const;

	U8 numEdgeShapes() const;
	EdgeShape getEdgeShape( EdgeID idx ) const;

	TileShapeIterator beginShape() const;
	TileShapeIterator endShape() const;
	TileShapeIteratorProxy shape() const;

	TileShapePartIterator beginParts() const;
	TileShapePartIterator endParts() const;
	TilePartsIteratorProxy parts() const;

	U8 numVertices() const;
	const glm::dvec2& getVertex( U8 idx ) const;
	TilingVertexProxy vertices() const;

	U8 numAspects() const;
	const glm::dmat3& getAspectTransform( U8 idx ) const;
	const glm::dvec2& getT1() const;
	const glm::dvec2& getT2() const;

	FillAlgorithm fillRegion( 
		double xmin, double ymin, double xmax, double ymax, 
		bool dbg = false ) const;
	FillAlgorithm fillRegion( 
		const glm::dvec2& A, const glm::dvec2& B, 
		const glm::dvec2& C, const glm::dvec2& D, bool dbg = false ) const;
	U8 getColour( int t1, int t2, U8 aspect ) const;
	
	const TilingTypeData *getRawTypeData() const;
	
private:
	void recompute();

	TilingType tiling_type;
	U8 num_params;
	double parameters[6];

	// Computed locations of tiling vertices
	glm::dvec2 verts[6];

	// Computed transforms to carry edge shapes to edge positions, between
	// consecutive tiling vertices.  It's your responsibility to deal with
	// S and U edges.
	glm::dmat3 edges[6];
	// For each tiling edge, must we reverse the parameterization of the
	// path along that edge?
	bool reversals[6];

	// Transforms to carry tiles to aspects within one translational unit.
	glm::dmat3 aspects[12];
	glm::dvec2 t1;
	glm::dvec2 t2;

	// References to internal tables that generate matrices and vectors
	// to control tile shapes and positions.
	const TilingTypeData *ttd;
	const double *tiling_vertex_coefficients;
	const EdgeID *edge_shape_ids;
	const EdgeShape *edge_shapes;
	const bool *edge_shape_orientations;
	const double *aspect_xform_coefficients;
	const double *translation_vector_coefficients;
	const U8 *colouring;
};

inline TileShapeIterator::TileShapeIterator( 
		const IsohedralTiling& t, size_t num )
	: tiling( t )
	, edge_num( num )
{}

inline const glm::dmat3& TileShapeIterator::getTransform() const
{
	return tiling.edges[edge_num];
}

inline U8 TileShapeIterator::getId() const
{
	return tiling.edge_shape_ids[edge_num];
}

inline EdgeShape TileShapeIterator::getShape() const
{
	return tiling.edge_shapes[getId()];
}

inline bool TileShapeIterator::isReversed() const
{
	return tiling.reversals[edge_num];
}

inline bool TileShapeIterator::operator ==( 
	const TileShapeIterator& other ) const
{
	return (&tiling == &other.tiling) && (edge_num == other.edge_num);
}

inline bool TileShapeIterator::operator !=( 
	const TileShapeIterator& other ) const
{
	return (&tiling != &other.tiling) || (edge_num != other.edge_num);
}

inline const TileShapeIterator& TileShapeIterator::operator *()
{
	return *this;
}

inline const TileShapeIterator *TileShapeIterator::operator->()
{
	return this;
}

inline TileShapeIterator& TileShapeIterator::operator++()
{
	++edge_num;
	return *this;
}

inline TileShapeIterator TileShapeIterator::operator++( int )
{
	TileShapeIterator tsi( tiling, edge_num );
	++edge_num;
	return tsi;
}

inline TileShapeIterator& TileShapeIterator::operator--()
{
	--edge_num;
	return *this;
}

inline TileShapeIterator TileShapeIterator::operator--( int )
{
	TileShapeIterator tsi( tiling, edge_num );
	--edge_num;
	return tsi;
}

inline TileShapeIteratorProxy::TileShapeIteratorProxy(
		const IsohedralTiling& t )
	: tiling( t )
{}

inline TileShapeIterator TileShapeIteratorProxy::begin()
{
	return tiling.beginShape();
}

inline TileShapeIterator TileShapeIteratorProxy::end()
{
	return tiling.endShape();
}

inline TilePartsIteratorProxy::TilePartsIteratorProxy(
		const IsohedralTiling& t )
	: tiling( t )
{}

inline TileShapePartIterator TilePartsIteratorProxy::begin()
{
	return tiling.beginParts();
}

inline TileShapePartIterator TilePartsIteratorProxy::end()
{
	return tiling.endParts();
}

inline TilingVertexProxy::TilingVertexProxy( const IsohedralTiling& t )
	: tiling( t )
{}

inline const glm::dmat3& TileShapePartIterator::getTransform() const
{
	return xform;
}

inline U8 TileShapePartIterator::getId() const
{
	return edge_shape_id;
}

inline EdgeShape TileShapePartIterator::getShape() const
{
	return tiling.edge_shapes[ edge_shape_id ];
}

inline bool TileShapePartIterator::isReversed() const
{
	return rev;
}

inline bool TileShapePartIterator::isSecondPart() const
{
	return (part == 1);
}

inline bool TileShapePartIterator::operator ==( 
		const TileShapePartIterator& other ) const
{
	return (&tiling == &other.tiling)
		&& (edge_num == other.edge_num)
		&& (part == other.part);
}

inline bool TileShapePartIterator::operator !=( 
		const TileShapePartIterator& other ) const
{
	return (&tiling != &other.tiling)
		|| (edge_num != other.edge_num)
		|| (part != other.part);
}

inline const TileShapePartIterator& TileShapePartIterator::operator *()
{
	return *this;
}

inline const TileShapePartIterator *TileShapePartIterator::operator->()
{
	return this;
}

inline const glm::dvec2 *TilingVertexProxy::begin() const
{
	return tiling.verts;
}

inline const glm::dvec2 *TilingVertexProxy::end() const
{
	return tiling.verts + tiling.numVertices();
}

inline glm::dmat3 FillRegionIterator::getTransform() const
{
	glm::dmat3 M( algo.tiling.getAspectTransform( asp ) );
	const glm::dvec2& t1 = algo.tiling.getT1();
	const glm::dvec2& t2 = algo.tiling.getT2();

	M[2][0] += int(x)*t1.x + int(y)*t2.x;
	M[2][1] += int(x)*t1.y + int(y)*t2.y;

	return M;
}

inline int FillRegionIterator::getT1() const
{
	return int(x);
}

inline int FillRegionIterator::getT2() const
{
	return int(y);
}

inline size_t FillRegionIterator::getAspect() const
{
	return asp;
}

inline bool FillRegionIterator::operator !=( 
	const FillRegionIterator& other ) const
{
	return !( *this == other );
}

inline const FillRegionIterator& FillRegionIterator::operator *()
{
	return *this;
}

inline const FillRegionIterator *FillRegionIterator::operator->()
{
	return this;
}

inline FillRegionIterator& FillRegionIterator::operator++()
{
	inc();
	return *this;
}

inline FillRegionIterator FillRegionIterator::operator++( int )
{
	FillRegionIterator fri( *this );
	inc();
	return fri;
}

inline const glm::dvec2& IsohedralTiling::getT1() const
{
	return t1;
}

inline const glm::dvec2& IsohedralTiling::getT2() const
{
	return t2;
}
	
inline const TilingTypeData *IsohedralTiling::getRawTypeData() const
{
    return ttd;
}

inline TileShapeIterator IsohedralTiling::beginShape() const
{
	return TileShapeIterator( *this, 0 );
}

inline TileShapeIterator IsohedralTiling::endShape() const
{
	return TileShapeIterator( *this, numVertices() );
}

inline TileShapePartIterator IsohedralTiling::beginParts() const
{
	return TileShapePartIterator( *this, 0 );
}

inline TileShapePartIterator IsohedralTiling::endParts() const
{
	return TileShapePartIterator( *this, numVertices() );
}

inline TileShapeIteratorProxy IsohedralTiling::shape() const
{
	return TileShapeIteratorProxy( *this );
}

inline TilePartsIteratorProxy IsohedralTiling::parts() const
{
	return TilePartsIteratorProxy( *this );
}

inline TilingVertexProxy IsohedralTiling::vertices() const
{
	return TilingVertexProxy( *this );
}

};

#endif // __TILING_HPP__
