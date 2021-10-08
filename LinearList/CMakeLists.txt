cmake_minimum_required(VERSION 3.13)

project(main)

file(GLOB SOURCES src/*.cpp src/*.h)

add_executable(main ${SOURCES})