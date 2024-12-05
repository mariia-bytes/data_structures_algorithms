/*********************************************************************************
 * This Node.h include implimentation if a Node class that is a primary element 
 * of a single linked list class which is defined in Singly_Linkd_List.h file and 
 * implemented in Singly_Linked_List.cpp file.
********************************************************************************/

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