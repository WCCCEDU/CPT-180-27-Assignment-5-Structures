cmake_minimum_required(VERSION 3.3)
project(CPT_180_27_Assignment_2_Config_Generator)

include_directories( ./lib )
link_directories( ./lib )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h)
add_executable(CPT_180_27_Assignment_2_Config_Generator ${SOURCE_FILES})
target_link_libraries(CPT_180_27_Assignment_2_Config_Generator config)