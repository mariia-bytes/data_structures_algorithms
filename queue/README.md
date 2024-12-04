# Queue Data Structure Implementation

## Introduction

This directory includes an implementation of a queue data structure.

## Why Use a Singly Linked List?

Although the most intuitive way to implement a queue might seem to be using a vector, the most **efficient** way is by using a singly linked list. With a singly linked list, adding (pushing) first element and removing (popping) last elements both have a time complexity of O(1), compared to O(n) and O(1) respectively when using a vector.

## Features

- **Enqueue**: Add an element to the end of the queue.
- **Dequeue**: Remove the last element of the queue and return its value.
- **Get first**: Return the value of the first element of the queue without removing it.
- **Get last**: Return the value of the last element of the queue without removing it.
- **Get lengtht**: Return the number of elements in the queue.

## Downsides

- Since this implementation uses a singly linked list, the queue is currently limited to holding only `int` values.


## File Structure

To help you navigate this stack project, every file includes a concise description:

- **Node.h**: Primary element of a singly linked list class.
- **Queue.h**: Declaration of the Queue class.
- **Queue.cpp**: Implementation of the Queue class.
- **Test.h**: Declaration of the test functions (which test every member function of the Queue class).
- **Test.cpp**: Implementation of the test functions.
- **main.cpp**: Contains the `main` function to run tests and demonstrate queue operations.

# Setup

To set up this project locally, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/mariia-bytes/data_structures_algorithms.git

2. **Create a build directory in the chosen project and navigate into it:**
    ```bash
    cd data_structure_algorithms/queue/
    mkdir build/
    cd build/

3. **Build the project using CMake:**
    ```bash
    cmake ..
    make

4. **Start the executable:**
    ```bash
    ./queue