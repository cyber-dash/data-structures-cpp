cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/sort.h src/bubble_sort.cpp src/heap_sort.cpp src/insert_sort.cpp src/merge_sort.cpp
        src/quick_sort.cpp src/select_sort.cpp src/util.h src/util.cpp src/main.cpp src/test.cpp src/test.h)