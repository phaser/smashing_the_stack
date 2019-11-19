# Introduction

Tests following the smashing the stack paper (see docs folder for the paper)

# Compiling

```bash
cd $REPO  # the git repository
mkdir build
cd build
cmake -G "Unix Makefiles" ../
make
```

# Directory structure

  * smash - all the source files
  * docs - relevant info about following the paper on a newer machine
  * CMakeLists.txt - The main CMake file that builds everything
  * README.md - This readme
