# Tactile
Tactile is a C++ library for representing, manipulating, and drawing tilings of the plane.  The tilings all belong to a special class called the _isohedral tilings_. Every isohedral tiling is formed from repeated copies of a single shape, and the pattern of repetition is fairly simple. At the same time, isohedral tilings are very expressive (they form the basis for a lot of the tessellations created by M.C. Escher) and efficient to compute.

I created the first versions of Tactile in the late 1990s, while working on my [PhD][phd].  This new version is based on a great deal of reflection on the strengths and weaknesses of that old code, not to mention a lot of polish to take advantage of (relatively) modern C++ coding practices and reduce dependencies on ancient libraries.  The result is lightweight, compact and fast (indeed, it's almost entirely table-driven).  The core library depends only on [`GLM`][glm] in order to represent points and matrices, though I also include an interactive demo that uses [`GLFW`][glfw], [`nanovg`][nanovg], and [`ImGui`][imgui] (snapshots of which are included here for convenience). If C++ isn't your cup of tea, you may prefer to experiment with [TactileJS][tactilejs], a Javascript port of this library.

I will provide more complete documentation here in the near future.  In the meantime it is possible to understand how to use the library by reading the source code of the demo programs, especially the thoroughly documented `demo/psdemo.cpp`.

## Building Tactile

The library is small and self-contained, and no special build instructions are required.  Simply make sure that `tactile.hpp` is in your include path, and that you can find the `GLM` headers.  Then compile `tactile.cpp` in with the rest of your code.  There's no need to worry explicitly about `tiling_arraydecl.inc`—that file is included by `tactile.cpp`.

## A crash course on isohedral tilings

In order to understand how to use Tactile, it might first be helpful to become acquainted with the Isohedral tilings.  The ultimate reference on the subject is the book _Tilings and Patterns_ by Grünbaum and Shephard.  You could also have a look at my book, [_Introductory Tiling Theory for Computer Graphics_][mybook], which is much slimmer and written more from a computer science perspective.  If you want a quick and free introduction, you could look through Chapters 2 and 4 of [my PhD thesis][phd].

Every isohedral tiling is made from repeated copies of a single shape called the _prototile_, which repeats in a very orderly way to fill the plane. We can describe the prototile's shape by breaking it into _tiling edges_, the shared boundaries between adjacent tiles, which connect at _tiling vertices_, the points where three or more tiles meet.  There are 93 "tiling types", different ways that tiles can relate to each other. Of these, 12 are boring for reasons I won't talk about here; this library lets you manipulate the other 81 types.

For each isohedral tiling type, there are constraints on the legal relationships between the tiling vertices.  Those constraints can be encoded in a set of _parameters_, which are just real numbers.  Some tiling types have zero parameters (their tiling vertices must form a fixed shape, like a square or a hexagon); others have as many as six free parameters.

## Constructing a tiling

The class `csk::IsohedralTiling` can be used to describe a specific tiling and its prototile.  It has a single constructor that takes the desired tiling type as an argument.  The tiling type is expressed as an integer representing a legal isohedral type.  These are all numbers between 1 and 93 (inclusive), but there are some holes—for example, there is no Type 19.  The array `csk::tiling_types`, with length `csk::num_types` (fixed at 81) contains the legal types:

```for( size_t idx = 0; idx < csk::num_types; ++idx ) {
    csk::IsohedralTiling a_tiling( csk::tiling_types[ idx ] );
    // Do something with this tiling type
}
```

[phd]: http://www.cgl.uwaterloo.ca/csk/phd/
[glm]: https://glm.g-truc.net/
[glfw]: https://www.glfw.org/
[nanovg]: https://github.com/memononen/nanovg
[imgui]: https://github.com/ocornut/imgui
[tactilejs]: https://github.com/isohedral/tactile-js
[mybook]: https://www.morganclaypool.com/doi/abs/10.2200/S00207ED1V01Y200907CGR011]
