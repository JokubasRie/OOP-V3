cmake_minimum_required(VERSION 3.29)
project(1_1uzd)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(1_1uzd
    functions.cpp
    functions.h
    main.cpp
    Mylib.h
    student.h)
