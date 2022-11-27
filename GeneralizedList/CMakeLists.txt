cmake_minimum_required(VERSION 3.21)

project(main)

include_directories("./*")

add_executable(main
    src/gen_list.h
    src/main.cpp
    src/test.cpp
    src/test.h
        src/simple_gen_list.h src/simple_gen_list.cpp)
