cmake_minimum_required(VERSION 3.13)

project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main src/main.cpp src/threaded_node.h src/inorder_threaded_binary_tree.h src/test.h src/test.cpp src/preorder_threaded_binary_tree.h src/postorder_threaded_binary_tree.h)
