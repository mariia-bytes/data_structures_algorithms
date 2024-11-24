# Stack Data Structure Implementation

## Introduction

This directory includes an implementation of a stack data structure.

## Why Use a Singly Linked List?

Although the most intuitive way to implement a stack might seem to be using a vector, the most **efficient** way is by using a singly linked list. With a singly linked list, adding (pushing) and removing (popping) elements both have a time complexity of O(1), compared to O(n) when using a vector.

## Features

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove and return the top element from the stack.
- **Peek**: Return the top element without removing it.
- **IsEmpty**: Check if the stack is empty.

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