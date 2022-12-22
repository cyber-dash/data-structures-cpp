cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 11)

project(Graph)

include_directories("./*")

add_executable(main
        src/graph.h
        src/matrix_graph.h
        src/adjacency_list_graph.h
        src/graph_algorithm.h
        src/graph_algorithm.cpp
        src/disjoint_set.h
        src/disjoint_set.cpp
        src/test.h
        src/test.cpp
        src/main.cpp
        src/priority_queue.h
)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror -std=c++1y)
endif()
