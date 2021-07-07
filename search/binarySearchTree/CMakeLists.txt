cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main binary_search_tree.h person.h main.cpp test.cpp test.h AVL_tree.h)
