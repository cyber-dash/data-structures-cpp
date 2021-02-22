cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main sort.h bubble_sort.cpp heap_sort.cpp insert_sort.cpp merge_sort.cpp
        quick_sort.cpp select_sort.cpp util.h util.cpp main.cpp test.cpp test.h)