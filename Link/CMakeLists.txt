cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/main.cpp src/node.h src/link_list.cpp src/link_list.h)