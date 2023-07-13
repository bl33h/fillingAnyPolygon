# fillingAnyPolygon
The project utilizes a framebuffer to enable drawing and filling polygons of various shapes and colors. The resulting image is saved in the build folder after running the application. 
In this branch, the generated bitmap (BMP) file will only contain the star.
<p align="center">
  <br>
  <img src="https://i.imgur.com/HgDPJO5.png" alt="pic" width="500">
  <br>
</p>
<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- src: the file that implements de solution.
  - colors.h: defines the Color struct and related functions for manipulating colors.
  - framebuffer.h: contains the framebuffer and related functions for drawing and filling polygons.
  - point.h: defines the vert struct representing a vertex in a polygon.
  - main.cpp: the main program that uses the framebuffer to render polygons and generate the BMP files.
  - out2.bmp: the bitmap file generated for the star polygon.
- CMakeLists.txt: the CMake configuration.

## Features
The fillingAnyPolygon project provides the following features:
- Drawing and filling polygons: The project allows you to define polygons using a list of vertices and specify their outline color and fill color.
- Outline rendering: The project can render the outline of a polygon using the Bresenham's line drawing algorithm.
- Polygon filling: The project can fill a polygon using the scanline algorithm to determine the intersection points of the polygon edges with the scanlines.
- Bitmap generation: The project generates a bitmap (BMP) file as the output, representing the rendered polygons.

## How To Use
To clone and run this application, you'll need [Git](https://git-scm.com), [CMake](https://cmake.org/download/), [Chocolatey](https://docs.chocolatey.org/en-us/choco/setup) (in order to execute Make) and a [C++ compiler](https://www.fdi.ucm.es/profesor/luis/fp/devtools/mingw.html) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/bl33h/fillingAnyPolygon

# Open the folder
$ cd src

# Run and build the app using CMake
$ cmake -G "Unix Makefiles" -S . -B build
$ cd build/
$ make
$ GAME.exe
```

Note: The main branch was created by merging the changes from the following branches: polygon-1, polygon-2, polygon-3, and polygon-4.
