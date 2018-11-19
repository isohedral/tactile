## This isn't a newfangled, cross-platform, all-purpose Makefile.  You'll 
## probably have to customize it to get it to build on other computers,
## especially non-Mac computers.

SIMP_INC = -I../deps/glm 

INCLUDES = $(SIMP_INC) \
	-I../deps/gl3w/build/include \
	-I../deps/glfw-3.2.1/include \
	-I../deps/imgui-1.65 \
	-I../deps/imgui-1.65/examples \
	-I../deps/nanovg/src

CC = clang
CPP = clang++
CFLAGS = $(INCLUDES) -I../src -g -Wall 
CPPFLAGS = $(INCLUDES) -I../src -g -Wall -std=c++11 
SIMP_CPPFLAGS = $(SIMP_INC) -I../src -g -Wall -std=c++11 

## This is probably the only platform dependency.  Edit as necessary.
LIBS = -L../deps/glfw-3.2.1/build/src -lglfw3 \
	-framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo

demo: demo.o nanovg.o imgui_impl.o gl3w.o tiling.o 
	$(CPP) -o $@ $^ $(LIBS)

psdemo: psdemo.o tiling.o
	$(CPP) -o $@ $^ 

demo.o: demo.cpp
	$(CPP) $(CPPFLAGS) $^ -c -o $@

## Glom all of imgui together into one compilation unit
imgui_impl.o: imgui_impl.cpp
	$(CPP) $(CPPFLAGS) $^ -c -o $@

## nanovg doesn't require a fancy build process, so do it here
nanovg.o: ../deps/nanovg/src/nanovg.c
	$(CC) $(CFLAGS) $^ -c -o $@

## gl3w is even simpler
gl3w.o: ../deps/gl3w/build/src/gl3w.c
	$(CC) $(CFLAGS) $^ -c -o $@

## And my library is inspired by the simple ones above.  Throw it in!
## This compilation unit doesn't need all the other header files, just
## GLM.
tiling.o: ../src/tiling.cpp ../src/tiling_arraydecl.inc
	$(CPP) $(SIMP_CPPFLAGS) ../src/tiling.cpp -c -o $@

psdemo.o: psdemo.cpp
	$(CPP) $(SIMP_CPPFLAGS) $^ -c -o $@

clean:
	rm -f *.o demo psdemo imgui.ini
