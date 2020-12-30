# cmake_minimum_required(VERSION <specify CMake version here>)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories("01 动态数组")

add_executable(DataStructure
        "01 动态数组/01 动态数组.c"
        "01 动态数组/DynamicArray.c"
        "01 动态数组/DynamicArray.h")
