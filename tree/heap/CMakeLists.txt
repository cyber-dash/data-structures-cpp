cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main main.cpp min_heap.cpp min_heap.h)
