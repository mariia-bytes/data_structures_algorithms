cmake_minimum_required(VERSION 3.16)
project(stack)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the shared header file
include_directories(${PROJECT_SOURCE_DIR})

# Create an executable
add_executable(stack
    main.cpp
    Node.h
    Stack.cpp
    Test.cpp
)