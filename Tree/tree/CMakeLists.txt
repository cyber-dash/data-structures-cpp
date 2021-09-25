cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/tree.cpp src/main.cpp src/tree.h src/tree_node.h)
