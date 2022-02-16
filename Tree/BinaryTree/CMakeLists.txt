cmake_minimum_required(VERSION 3.21)

project(main)

include_directories("./*")

add_executable(main src/main.cpp src/binary_tree.h src/test.h)
