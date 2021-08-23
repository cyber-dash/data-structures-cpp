cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main cyber_dash_string.h main.cpp cyber_dash_string.cpp test.cpp test.h)