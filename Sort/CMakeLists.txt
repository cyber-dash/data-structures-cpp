cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main
        src/bubble_sort.h
        src/heap_sort.h
        src/insertion_sort.h
        src/merge_sort.h
        src/quick_sort.h
        src/selection_sort.h
        src/radix_sort_for_linked_list.h
        src/util.h
        src/main.cpp
        src/test.cpp
        src/test.h src/radix_sort.h src/radix_sort.h)