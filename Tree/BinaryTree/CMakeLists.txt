cmake_minimum_required(VERSION 3.21)

project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(main src/main.cpp src/binary_tree.h src/test.h)
