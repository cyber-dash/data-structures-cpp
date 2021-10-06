cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main src/main.cpp src/disjoint_set.cpp src/disjoint_set.h src/set.h src/bit_set.h src/link_set.h src/dictionary.h src/hash_table_linear_probing.h src/test.cpp src/test.h src/hash_table_quadratic_probing.h)
