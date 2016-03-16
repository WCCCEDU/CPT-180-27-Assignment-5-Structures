cmake_minimum_required(VERSION 3.3)
project(lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Assignment3-Libraries.h)
add_library(lib ${SOURCE_FILES})