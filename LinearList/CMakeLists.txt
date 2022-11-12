cmake_minimum_required(VERSION 3.22)

project(main)

set(CMAKE_CXX_STANDARD 98)

#file(GLOB SOURCES src/*.cpp src/*.h)
#add_executable(main ${SOURCES})

add_executable(main src/circular_doubly_linked_list.h src/circular_doubly_linked_list_test.h src/linear_list.h
        src/singly_linked_list.h src/singly_linked_list_test.h src/main.cpp src/seq_list.h src/seq_list_algorithm.h
        src/seq_list_test.h)
