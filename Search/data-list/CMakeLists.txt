cmake_minimum_required(VERSION 3.13)

project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main src/data_list.h src/search_list.h
    src/test.h src/test.cpp src/main.cpp src/sorted_list.h)
