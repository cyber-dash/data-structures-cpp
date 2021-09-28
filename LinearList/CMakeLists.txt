cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main
    src/main.cpp
    src/seq_list.h
    src/link_list.h
    src/double_link_list.h
    src/seq_list_test.h
    src/seq_list_algorithm.h
    src/link_list_test.h)
