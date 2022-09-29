cmake_minimum_required(VERSION 3.0)
project(example)
set (CMAKE_C_COMPILER "/usr/local/gcc-11.2/bin//gcc-11.2")
set (CMAKE_CXX_COMPILER "/usr/local/gcc-11.2/bin//g++-11.2")
add_compile_options(-g -Wall -std=c++20)
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB CPP_SRC_PATH src/*.cpp src/*.ixx)
#线程库
#LINK_LIBRARIES(-lpthread)
add_executable(example ${CPP_SRC_PATH})

