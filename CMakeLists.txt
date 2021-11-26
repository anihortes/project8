cmake_minimum_required(VERSION 3.17)
project(project8)

set(CMAKE_CXX_STANDARD 17)
add_executable(project8 squarer.h squarer_test.cpp doctest.h)
#add_executable(project8 string_read_main.cpp string_read.cpp string_read.hpp)