cmake_minimum_required(VERSION 4.0)
project(non_linear_data_structure)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)

add_executable(non_linear_data_structure main.cpp
        headers/BSTree.h
        headers/BTree.h
        src/travelling-salesman-problem/brute-force/case_1_5_cities.cpp
        src/travelling-salesman-problem/brute-force/case_1_18_cities.cpp
        src/travelling-salesman-problem/brute-force/utils.h
        src/travelling-salesman-problem/dijkstra.cpp
)
