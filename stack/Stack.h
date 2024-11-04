/***************************************************
 * This Stack.h file include Stack class based on
 * single linked list data structure 
 * (look READM.md for reasons behind that choice).
 * 
 * Implimentation of the member functions can be
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
        Stack(int value) {
            Node* new_node = new Node(value);
            top = new_node;
            height = 1;
        }

        // basic getters
        void get_top() {
            std::cout << "Top: " << top->value << std::endl;
        }

        void get_height() {
            std::cout << "Height: " << height << std::endl;
        }
};

#endif // _STACK_H_

