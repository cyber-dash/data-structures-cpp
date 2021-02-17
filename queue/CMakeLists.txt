cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main link_queue.h main.cpp link_queue.cpp link_node.h)