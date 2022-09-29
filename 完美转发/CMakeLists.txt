cmake_minimum_required(VERSION 3.0)
project(C++Template)
set (CMAKE_C_COMPILER "gcc")
set (CMAKE_CXX_COMPILER "g++")
set (PROJECT_NAME factory)


#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_compile_options(-o2 -Wall -std=c++20)
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB CPP_SRC_PATH src/*.cpp)
#线程库
#LINK_LIBRARIES(-lpthread)
add_executable(${PROJECT_NAME} ${CPP_SRC_PATH})

