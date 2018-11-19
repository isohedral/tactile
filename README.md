# Tactile
Tactile is a C++ library for representing, manipulating, and drawing tilings of the plane.  The tilings all belong to a special class called the _isohedral tilings_. Every isohedral tiling is formed from repeated copies of a single shape, and the pattern of repetition is fairly simple. At the same time, isohedral tilings are very expressive (they form the basis for a lot of the tessellations created by M.C. Escher) and efficient to compute.

I created the first versions of Tactile in the late 1990s, while working on my [PhD][phd].  This new version is based on a great deal of reflection on the strengths and weaknesses of that old code, not to mention a lot of polish to take advantage of modern C++ coding practices and reduce dependencies on ancient libraries.  The result is lightweight, compact and fast (indeed, it's almost entirely table-driven).  The core library depends only on [`GLM`][glm] in order to represent points and matrices, though I also include an interactive demo that uses [`GLFW`][glfw], [`nanovg`][nanovg], and [`ImGui`][imgui] (snapshots of which are included here for convenience).

I will provide more complete documentation here in the near future.  In the meantime it is possible to understand how to use the library by reading the source code of the demo programs, especially the thoroughly documented `demo/psdemo.cpp`.

[phd]: http://www.cgl.uwaterloo.ca/csk/phd/
[glm]: https://glm.g-truc.net/
[glfw]: https://www.glfw.org/
[nanovg]: https://github.com/memononen/nanovg
[imgui]: https://github.com/ocornut/imgui
