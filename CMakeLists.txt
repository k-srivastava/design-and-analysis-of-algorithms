cmake_minimum_required(VERSION 3.27)
project(design_of_algorithms C)

set(CMAKE_CXX_COMPILER "/usr/bin/clang-17")
set(CMAKE_C_STANDARD 17)

add_executable(design_of_algorithms main.c
        src/Q1/binary_tree.h
        src/Q1/graph.h
        src/Q3/sort.h
        src/Q3/substring.h
        src/Q2/gcd.h
        src/Q3/matrix.h
        src/Q3/partition.h
        src/Q4/travelling_salesman.h
        src/Q4/assignment.h
        src/Q5/topological_sort.h
        src/utils/stack.h
        src/utils/queue.h
        src/utils/stack.c
        src/utils/queue.c
        src/Q2/fibonacci.h
        src/lookup/sort.h
        src/lookup/sort.c
        src/utils/array.h
        src/utils/binary_tree.h
        src/utils/binary_tree.c
        src/Q5/tree_diameter.h
        src/utils/utils.c
        src/utils/utils.h
        src/utils/avl_tree.c
        src/utils/avl_tree.h
        src/Q4/knapsack.h
        src/lookup/graphs.c
        src/lookup/graphs.h
        src/lookup/string_matching.c
        src/lookup/string_matching.h
        src/lookup/trees.c
        src/lookup/trees.h
        src/lookup/combinatorics.c
        src/lookup/combinatorics.h
        src/lookup/utils.h
        src/lookup/utils.c
)
