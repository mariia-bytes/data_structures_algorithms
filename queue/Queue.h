/***************************************************
 * This Queue.h file include Stack class based on
 * single linked list data structure 
 * (look READM.md for reasons behind that choice).
 * 
 * Implementation of the member functions can be
 * found in Queue.cpp file.
 * 
 * Stack is FIFO data structure
***************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

class Queue {
    friend std::ostream &operator<<(std::ostream& os, const Queue* queue);
    private:
        Node* first;
        Node* last;
        int length;
    public:
        // constructor
        Queue(int value);
        // destructor
        ~Queue();

        // basic getters
        void get_first() const;
        void get_last() const;
        void get_length() const;

        // add an item with a particular value to the end of the Q
        void enqueue(const int value);

        // remove the first item from the Q
        int dequeue();
};

#endif