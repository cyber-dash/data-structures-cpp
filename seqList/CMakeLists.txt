cmake_minimum_required(VERSION 3.13)

project(main)

include_directories("./*")

add_executable(main SeqList.cpp main.cpp SeqList.h)
