cmake_minimum_required(VERSION 3.16)
project(queue)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the shared header file
include_directories(${PROJECT_SOURCE_DIR})

# Create an executable
add_executable(queue
    main.cpp
    Node.h
    Queue.cpp
    Test.cpp
)