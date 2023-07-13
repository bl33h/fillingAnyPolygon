# fillingAnyPolygon

<p align="center">
  <br>
  <img src="https://i.imgur.com/fXGj8nP.png" alt="pic" width="500">
  <br>
</p>
<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- src: the file that implements de solution.
  - colors.h:
  - framebuffer.h:
  - point.h:
  - main.cpp:
  - out.bmp:
  - out2.bmp:
  - out3.bmp:
  - out4.bmp:
  - out5.bmp:
- CMakeLists.txt: the CMake configuration.

## Features
A

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

Note: the bmp file will be generated in the 'build' folder, open it to see the outcome of the code.
