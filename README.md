# Installation

---

**Windows & Cmake:**
1. Install SFML from this website: https://www.sfml-dev.org/download/sfml/2.6.1/
   - Please ensure you are using the correct MinGW version for your system.
2. Modify your `CMakeLists` file to include the following:
```cmake
cmake_minimum_required(VERSION 3.14)
project(cellviz)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "your path to sfml")
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)
add_definitions(-DSFML_STATIC)

add_executable(cellviz src/main.cpp)

target_link_libraries(cellviz sfml-graphics sfml-audio sfml-system sfml-window)
```
3. Copy all the .dll files from `{SFML_DIR}/bin/` to your `cmake-build-debug/` folder (or wherever your build is).
4. Build and run.

**Linux/MacOS:**
1. Run some goofy command that does it all for you.
2. Profit.