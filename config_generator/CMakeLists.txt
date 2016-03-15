cmake_minimum_required(VERSION 3.3)
project(config_generator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp structures_header.h)
add_executable(config_generator ${SOURCE_FILES})