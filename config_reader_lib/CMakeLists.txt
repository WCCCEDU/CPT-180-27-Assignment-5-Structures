cmake_minimum_required(VERSION 3.3)
project(CPT-180-27-Assignment-5-Structures-config_writer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES config.cpp config.h)
# add_executable(CPT_180_27_Assignment_3_Libraries ${SOURCE_FILES})
add_library (config ${SOURCE_FILES})