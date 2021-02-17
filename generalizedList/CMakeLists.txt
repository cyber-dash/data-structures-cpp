cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main gen_list.h gen_list.cpp main.cpp)