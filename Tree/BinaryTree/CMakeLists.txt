cmake_minimum_required(VERSION 3.21)

project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main src/main.cpp src/binary_tree.h src/test.h)
