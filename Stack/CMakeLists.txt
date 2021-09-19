cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/link_stack.h src/main.cpp)
