cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./src/*")

add_executable(main src/main.cpp src/sparse_matrix.h src/test.cpp src/test.h)
