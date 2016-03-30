cmake_minimum_required(VERSION 3.3)
project(Assignment2_Config_Files)

include_directories("C:\\Users\\Samantha\\Documents\\Schoolwork\\Libraries")
link_directories("C:\\Users\\Samantha\\Documents\\Schoolwork\\Libraries")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp configheader.h)
add_executable(Assignment2_Config_Files ${SOURCE_FILES})

target_link_libraries(Assignment2_Config_Files lib)