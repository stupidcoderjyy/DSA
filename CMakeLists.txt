cmake_minimum_required(VERSION 3.31)
project(DSA)

add_subdirectory(project/student_ms)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA
        code/2025_10_17/dynamic_cast.cpp
)
