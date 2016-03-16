cmake_minimum_required(VERSION 3.3)
project(CPT-180-27-Assignment-5-Structures-config_generator)

include_directories( ./lib )
link_directories( ./lib )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h)
add_executable(CPT-180-27-Assignment-5-Structures-config_generator ${SOURCE_FILES})
target_link_libraries(CPT-180-27-Assignment-5-Structures-config_generator config)