cmake_minimum_required(VERSION 3.0)
project(C++Template)
set (CMAKE_C_COMPILER "/usr/local/gcc-11.2/bin/gcc-11.2")
set (CMAKE_CXX_COMPILER "/usr/local/gcc-11.2/bin/g++-11.2")
set (PROJECT_NAME example)


#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_compile_options(-g -Wall -std=c++20)
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB CPP_SRC_PATH src/*.cpp)
#线程库
#LINK_LIBRARIES(-lpthread)
add_executable(${PROJECT_NAME} ${CPP_SRC_PATH})

