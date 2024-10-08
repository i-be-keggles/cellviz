cmake_minimum_required(VERSION 3.14)
project(cellviz)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Program Files/SFML-2.6.1/")
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)
add_definitions(-DSFML_STATIC)

add_executable(cellviz src/main.cpp)

target_link_libraries(cellviz sfml-graphics sfml-audio sfml-system sfml-window)