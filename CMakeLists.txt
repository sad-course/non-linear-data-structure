cmake_minimum_required(VERSION 4.0)
project(non_linear_data_structure)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)

add_executable(non_linear_data_structure main.cpp
        headers/Node.h
        headers/BSTree.h)
