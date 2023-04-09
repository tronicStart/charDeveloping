cmake_minimum_required(VERSION 3.0)

project(CharDeveloping VERSION 1.0.0)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_INCLUDE_PATH "C:/Dev-Cpp/MinGW64/include/winapi")

add_executable(CharDeveloping "main.cpp" "resource.h" "resource.rc" "chardevelopingc.h")

target_link_libraries(CharDeveloping PUBLIC "${CMAKE_INCLUDE_PATH}")
