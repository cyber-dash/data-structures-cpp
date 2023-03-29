cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(main src/linked_stack.h src/main.cpp)
