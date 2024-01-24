cmake_minimum_required(VERSION 3.27)
project(design_of_algorithms C)

set(CMAKE_CXX_COMPILER "/usr/bin/clang-17")
set(CMAKE_C_STANDARD 17)

add_executable(design_of_algorithms main.c
        src/Q1/binary_tree.h
        src/Q1/graph.h
        src/Q3/sort.h
        src/Q3/substring.h)
