cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/bubble_sort.h src/heap_sort.h src/insert_sort.h src/merge_sort.h
        src/quick_sort.h src/select_sort.h src/util.h src/main.cpp src/test.cpp src/test.h)