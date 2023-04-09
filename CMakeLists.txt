cmake_minimum_required(VERSION 3.0)
project(CharDeveloping VERSION 1.0.0)
add_executable(CharDeveloping "main.cpp" "resource.h" "resource.rc" "chardevelopingc.h")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

