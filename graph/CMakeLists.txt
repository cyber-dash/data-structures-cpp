cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main graph.h graph_matrix.h graph_adjacency_list.h graph_algorithm.h graph_algorithm.cpp
    disjoint_set.h disjoint_set.cpp
    test.h test.cpp main.cpp)
