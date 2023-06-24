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

add_executable(main
    src/gen_list.h
    src/main.cpp
    src/test.cpp
    src/test.h
        src/simple_gen_list.h src/simple_gen_list.cpp)
