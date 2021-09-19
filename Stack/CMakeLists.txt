cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main link_stack.h main.cpp link_stack.cpp link_node.h)
