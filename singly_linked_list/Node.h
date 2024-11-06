/**********************************************
 * This Node.h include implimentation if a 
 * Node class that is a primary element 
 * of a single linked list class which is 
 * defined in Linkd_List.h file and member 
 * functions of which implemented in
 *  Linked_List.cpp file.
**********************************************/

#ifndef NODE_H
#define NODE_H

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }
};

#endif // NODE_H