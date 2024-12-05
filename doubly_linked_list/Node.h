/*********************************************************************************
 * This Node.h include implimentation if a Node class that is a primary element 
 * of a doubly linked list class which is defined in Doubly_Linkd_List.h file and 
 * implemented in Doubly_Linked_List.cpp file.
********************************************************************************/

#ifndef NODE_H
#define NODE_H

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

    Node (int value)
        : value(value), next(nullptr), prev(nullptr) {}
};

#endif // NODE_H