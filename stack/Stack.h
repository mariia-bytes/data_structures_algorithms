/***************************************************
 * This Stack.h file include Stack class based on
 * single linked list data structure 
 * (look READM.md for reasons behind that choice).
 * 
 * Implementation of the member functions can be
 * found in Stack.cpp file.
***************************************************/

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include "Node.h"

class Stack {
    friend std::ostream &operator<<(std::ostream &os, const Stack* top);
    private:
        Node* top; // equivalent of a head in SLL
        int height;

    public:
        // constructor
        Stack(int value);

        // destructor
        ~Stack();

        // basic getters
        void get_top();
        void get_height();

        // push (add) an item with a given value
        // basically a prepend function in SLL
        void push(int value);

        // pop (remove) a top item in a S
        // similar to delete_first in SLL
        int pop(); // returns a value of popped element
};

#endif // _STACK_H_

