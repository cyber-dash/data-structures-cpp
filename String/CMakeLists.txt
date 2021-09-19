cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/cyber_dash_string.h src/main.cpp src/test.cpp src/test.h)