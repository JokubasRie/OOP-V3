cmake_minimum_required(VERSION 3.29)
project(2strategijaVector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2strategijaVector
    functions.cpp
    functions.h
    main.cpp
    Mylib.h
    student.h)
