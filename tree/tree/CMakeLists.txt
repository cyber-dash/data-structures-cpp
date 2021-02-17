cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main tree.cpp main.cpp tree.h tree_node.h)
