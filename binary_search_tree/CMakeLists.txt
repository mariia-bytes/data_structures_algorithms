cmake_minimum_required(VERSION 3.16)
project(binary_search_tree)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the shared header file
include_directories(${PROJECT_SOURCE_DIR})

# Create an executable
add_executable(binary_search_tree
    main.cpp
    Node.h
    Binary_Search_Tree.cpp
    Test.cpp
)