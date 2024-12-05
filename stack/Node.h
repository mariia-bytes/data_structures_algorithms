/******************************************************************************
 * This Node.h include implimentation if a Node class that is a primary element 
 * of a Stack which is defined in Stack.h file implemented in Stack.cpp file.
******************************************************************************/

#ifndef NODE_H
#define NODE_H

class Node {
    public:
        int value;
        Node* next;

        Node(int value)
            : value(value), next(nullptr) {}
};

#endif // NODE_H