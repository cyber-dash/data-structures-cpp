cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main main.cpp disjoint_set.cpp disjoint_set.h set.h bit_set.h link_set.h dictionary.h hash_table_linear_probing.h test.cpp test.h hash_table_quadratic_probing.h)
