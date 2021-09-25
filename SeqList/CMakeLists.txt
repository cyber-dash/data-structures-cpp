cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/main.cpp src/seq_list.h src/test.cpp src/test.h src/seq_list_algorithm.h)
