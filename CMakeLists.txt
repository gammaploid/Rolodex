cmake_minimum_required(VERSION 3.28)
project(rolodex)

set(CMAKE_CXX_STANDARD 17)

add_executable(rolodex main.cpp
        Rolodex.cpp
        test_rolodex.cpp
        test_rolodex.h)
