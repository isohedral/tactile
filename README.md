# Tactile
Tactile is a C++ library for representing, manipulating, and drawing tilings of the plane.  The tilings all belong to a special class called the _isohedral tilings_. Every isohedral tiling is formed from repeated copies of a single shape, and the pattern of repetition is fairly simple. At the same time, isohedral tilings are very expressive (they form the basis for a lot of the tessellations created by M.C. Escher) and efficient to compute.

I created the first versions of Tactile in the late 1990s, while working on my [PhD][phd].  This new version is based on a great deal of reflection on the strengths and weaknesses of that old code, not to mention a lot of polish to take advantage of (relatively) modern C++ coding practices and reduce dependencies on ancient libraries.  The result is lightweight, compact and fast (indeed, it's almost entirely table-driven).  The core library depends only on [`GLM`][glm] in order to represent points and matrices, though I also include an interactive demo that uses [`GLFW`][glfw], [`nanovg`][nanovg], and [`ImGui`][imgui] (snapshots of which are included here for convenience). If C++ isn't your cup of tea, you may prefer to experiment with [TactileJS][tactilejs], a Javascript port of this library.

## Building Tactile

The library is small and self-contained, and no special build instructions are required.  Simply make sure that `tactile.hpp` is in your include path, and that you can find the `GLM` headers.  Then compile `tactile.cpp` in with the rest of your code.  There's no need to worry explicitly about `tiling_arraydecl.inc`—that file is included by `tactile.cpp`.

The `demo/` directory contains a couple of demo programs.  The program `psdemo.cpp` has no requirements beyond `Tactile` and `GLM` and should be easy to build.  It outputs a "sample book" of randomly generated tilings, one per type.  For the interactive editor `demo.cpp` you may need to modify the `Makefile`.

## A crash course on isohedral tilings

In order to understand how to use Tactile, it might first be helpful to become acquainted with the Isohedral tilings.  The ultimate reference on the subject is the book _Tilings and Patterns_ by Grünbaum and Shephard.  You could also have a look at my book, [_Introductory Tiling Theory for Computer Graphics_][mybook], which is much slimmer and written more from a computer science perspective.  If you want a quick and free introduction, you could look through Chapters 2 and 4 of [my PhD thesis][phd].

Every isohedral tiling is made from repeated copies of a single shape called the _prototile_, which repeats in a very orderly way to fill the plane. We can describe the prototile's shape by breaking it into _tiling edges_, the shared boundaries between adjacent tiles, which connect at _tiling vertices_, the points where three or more tiles meet.

<p align="center"><img src="images/topo.png" height=250/></p>

There are 93 "tiling types", different ways that tiles can relate to each other. Of these, 12 are boring for reasons I won't talk about here; this library lets you manipulate the other 81 types.

For each isohedral tiling type, there are constraints on the legal relationships between the tiling vertices.  Those constraints can be encoded in a set of _parameters_, which are just real numbers.  Some tiling types have zero parameters (their tiling vertices must form a fixed shape, like a square or a hexagon); others have as many as six free parameters.

<p align="center"><img src="images/params.png" height=150/></p>

## Constructing a tiling

The class `csk::IsohedralTiling` can be used to describe a specific tiling and its prototile.  It has a single constructor that takes the desired tiling type as an argument.  The tiling type is expressed as an integer representing a legal isohedral type.  These are all numbers between 1 and 93 (inclusive), but there are some holes—for example, there is no Type 19.  The array `csk::tiling_types`, with length `csk::num_types` (fixed at 81) contains the legal types:

```C++
// Suppose you wanted to loop over all the tiling types...
for( size_t idx = 0; idx < csk::num_types; ++idx ) {
    // Create a new tiling of the given type, with default shape.
    csk::IsohedralTiling a_tiling( csk::tiling_types[ idx ] );
    // Do something with this tiling type
}
```

## Controlling parameters

You can get and set the parameters that control the positions of the tiling vertices through a `double` array:

```C++
size_t num_params = a_tiling.numParameters();
if( num_params > 1 ) {
    double params[ num_params ];
    // Get the parameters out of the tiling
    a_tiling.getParameters( params );
    // Change a parameter
    params[ 1 ] += 1.0;
    // Send the parameters back to the tiling
    a_tiling.setParameters( params );
}
```

Setting the parameters causes a lot of internal data to be recomputed (efficiently, but still), which is why all parameters should be set together in one function call.

## Prototile shape

As discussed above, a prototile's outline can be thought of as a sequence of tiling edges running between consecutive tiling vertices. Of course, in order to tile the plane, some of those edges must be transformed copies of others, so that a tile can interlock with its neighbours.  In most tiling types, then, there are fewer distinct _edge shapes_ than there are edges, sometimes as few as a single path repeated all the way around the tile. Furthermore, some edge shapes can have internal symmetries forced upon it by the tiling: 

<p align="center"><img src="images/jusi.png" height=100/></p>

 * Some edges must look the same after a 180° rotation, like a letter S.  We call these **S** edges.
 * Some edges must look the same after reflecting across their length, like a letter U.  We call these **U** edges.
 * Some edges must look the same after both rotation _and_ reflection. Only a straight line has this property, so we call these **I** edges.
 * All other edges can be a path of any shape.  We call these **J** edges.
 
Tactile assumes that an edge shape lives in a canonical coordinate system, as a path that starts at (0,0) and ends at (1,0). The library will then tell you the transformations you need to perform in order to map those canonical edges into position around the prototile's boundary. You can access this information by looping over the tiling edges using a C++ iterator:

```C++
// Iterate over the tiling's edges, getting information about each edge
for( auto i : a_tiling.shape() ) {
    // Determine which canonical edge shape to use for this tiling edge.
    // Multiple edges will have the same ID, indicating that the edge shape is
    // reused multiple times.
    csk::U8 id = i->getId();
    // Get a 3x3 transformation matrix that moves the edge from canonical
    // position into its correct place around the tile boundary.
    glm::dmat3 T = i->getTransform();
    // Get the intrinsic shape constraints on this edge shape: Is it
    // J, U, S, or I?  Here, it's your responsibility to draw a path that
    // actually has those symmetries.
    csk::EdgeShape shape = i->getShape();
    // When edges interlock, one copy must be parameterized backwards 
    // to fit with the rest of the prototile outline.  This boolean
    // tells you whether you need to do that.
    bool rev = i->isReversed();
    
    // Do something with the information above...
}
```

<p align="center"><img src="images/shape.png" height=250/></p>

Occasionally, it's annoying to have to worry about the **U** or **S** symmetries of edges yourself.  Tactile offers an alternative way to describe the tile's outline that includes extra steps that account for these symmetries.  In this case, the transformation matrices build in scaling operations that map a path from (0,0) to (1,0) to, say, each half of an **S** edge separately.  The correct approach here is to iterate over a tile's `parts()` rather than its `shape()`:

```C++
// Iterate over the tiling's edges, getting information about each edge
for( auto i : a_tiling.parts() ) {
    // As above.
    csk::U8 id = i->getId();
    // As above for J and I edges.  For U and S edges, include a scaling
    // operation to map to each half of the tiling edge in turn.
    glm::dmat3 T = i->getTransform();
    // As above
    csk::EdgeShape shape = i->getShape();
    // As above
    bool rev = i->isReversed();
    // For J and I edges, this is always false.  For U and S edges, this
    // will be false for the first half of the edge and true for the second.
    bool second = i->isSecondPart();
    
    // Do something with the information above...
}
```

When drawing a prototile's outline using `parts()`, a **U** edge's midpoint might lie anywhere on the perpendicular bisector of the line joining two tiling vertices. For that reason, you are permitted to make an exception and have the underlying canonical path end at (1,_y_) for any _y_ value.

Note that there's nothing in the description above that knows how paths are represented. That's a deliberate design decision that keeps the library lightweight and adaptable to different sorts of curves.  It's up to you to maintain a set of canonical edge shapes that you can transform and string together to get the final tile outline. The demo programs offer examples of doing this for polygonal paths and cubic Béziers.

## Laying out tiles

The core operation of tiling is to fill a region of the plane with copies of the prototile.  Tactile offers a simple iterator-based approach for doing this:

```C++
// Fill a rectangle given its bounds (xmin, ymin, xmax, ymax)
for( auto i : a_tiling.fillRegion( 0.0, 0.0, 8.0, 5.0 ) {
    // Get the 3x3 matrix corresponding to one of the transformed
    // tiles in the filled region.
    glm::dmat3 T = i->getTransform();
    // Use a simple colouring algorithm to pick a colour for this tile
    // so that adjacent tiles aren't the same colour.  The resulting
    // value col will be 0, 1, or 2, which you should map to your
    // three favourite colours.
    csk::U8 col = a_tiling.getColour( i->getT1(), i->getT2(), i->getAspect() );
}
```

There is an alternative form of `csk::IsohedralTiling::fillRegion()` that takes four points as arguments instead of bounds.

The region filling algorithm isn't perfect.  It's difficult to compute exactly which tiles are needed to fill a given rectangle, at least with high efficiency.  It's possible you'll generate tiles that are completely outside the window, or leave unfilled fringes at the edge of the window.  The easiest remedy is to fill a larger region than you need and ignore the extra tiles.  In the future I may work on improving the algorithm, perhaps by including an option that performs the extra computation when requested.

## In closing

I hope you find this library to be useful.  If you are using Tactile for research, for fun, or for commercial products, I would appreciate it if you'd let me know.  I'd be happy to list projects based on Tactile here, and it helps my research agenda to be able to say that the library is getting used.  Thank you.

[phd]: http://www.cgl.uwaterloo.ca/csk/phd/
[glm]: https://glm.g-truc.net/
[glfw]: https://www.glfw.org/
[nanovg]: https://github.com/memononen/nanovg
[imgui]: https://github.com/ocornut/imgui
[tactilejs]: https://github.com/isohedral/tactile-js
[mybook]: https://www.amazon.com/Introductory-Computer-Graphics-Synthesis-Animation/dp/1608450171]
