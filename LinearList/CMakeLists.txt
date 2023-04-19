cmake_minimum_required(VERSION 3.22)

project(main)

set(CMAKE_CXX_STANDARD 98)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(main src/circular_doubly_linked_list.h src/circular_doubly_linked_list_test.h src/linear_list.h
        src/singly_linked_list.h src/singly_linked_list_test.h src/main.cpp src/seq_list.h src/seq_list_algorithm.h
        src/seq_list_test.h src/doubly_linked_list.h src/doubly_linked_list_test.h src/circular_singly_linked_list.h src/circular_singly_linked_list_test.h src/static_linked_list.h src/static_linked_list_test.h)
