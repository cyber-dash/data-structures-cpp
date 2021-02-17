cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main main.cpp huffman_node.h huffman_tree.cpp huffman_tree.h min_heap.cpp min_heap.h)
