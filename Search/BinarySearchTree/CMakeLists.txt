cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(
    main
    src/binary_search_tree.h
    src/person.h
    src/main.cpp
    src/test.cpp
    src/test.h
    src/AVL_tree.h
)
