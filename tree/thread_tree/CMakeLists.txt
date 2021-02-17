cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main thread_tree.cpp main.cpp thread_tree.h)
