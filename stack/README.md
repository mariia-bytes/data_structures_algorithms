# Stack Data Structure Implementation

## Introduction

This directory includes an implementation of a stack data structure.

## Why Use a Singly Linked List?

Although the most intuitive way to implement a stack might seem to be using a vector, the most **efficient** way is by using a singly linked list. With a singly linked list, adding (pushing) and removing (popping) elements both have a time complexity of O(1), compared to O(n) when using a vector.

## Features

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove and return the top element from the stack.
- **Get top**: Return the value of the top element without removing it.
- **Get height**: Return the number of elements on the stack.

## Downsides

- Since this implementation uses a singly linked list, the stack is currently limited to holding only `int` values.


## File Structure

To help you navigate this stack project, every file includes a concise description:

- **Node.h**: Primary element of a singly linked list class.
- **Stack.h**: Declaration of the Stack class.
- **Stack.cpp**: Implementation of the Stack class.
- **Test.h**: Declaration of the test functions (they test every member function of the Stack class).
- **Test.cpp**: Implementation of the test functions.
- **main.cpp**: Contains the `main` function to run tests and demonstrate stack operations.

# Setup

To set up this project locally, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/mariia-bytes/data_structures_algorithms.git

2. **Create a build directory in the chosen project and navigate into it:**
    ```bash
    cd data_structure_algorithms/stack/
    mkdir build/
    cd build/

3. **Build the project using CMake:**
    ```bash
    cmake ..
    make

4. **Start the executable:**
    ```bash
    ./stack