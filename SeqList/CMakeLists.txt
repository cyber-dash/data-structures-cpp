cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main main.cpp seq_list.h test.cpp test.h seq_list_algorithm.h)
