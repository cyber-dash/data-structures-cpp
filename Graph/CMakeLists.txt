cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")


add_executable(main src/graph.h src/matrix_graph.h src/adjacency_list_graph.h src/graph_algorithm.h src/graph_algorithm.cpp
        src/disjoint_set.h src/disjoint_set.cpp
        src/test.h src/test.cpp src/main.cpp src/priority_queue.h)
