cmake_minimum_required(VERSION 3.31)
project(MS)

set(CMAKE_CXX_STANDARD 20)

add_executable(MS
        main.cpp
        Manager.h
        Manager.cpp
        Student.h
        Student.cpp
)
