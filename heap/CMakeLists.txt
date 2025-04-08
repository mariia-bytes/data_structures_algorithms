cmake_minimum_required(VERSION 3.16)
project(heap)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the shared header file
include_directories(${PROJECT_SOURCE_DIR})

# Create an executable
add_executable(heap
    main.cpp
    Heap.cpp
    Test.cpp
)