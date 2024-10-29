#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

#include <iostream>
#include "Node.h"

class D_Linked_List {
    friend std::ostream &operator<<(std::ostream &os, const D_Linked_List *list);
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        // constructor
        D_Linked_List(int value);

        // getters
        void get_head();
        void get_tail();
        void get_length();

        // add a node with given value to the begginig of the DLL
        void prepend(int value);

        // add a node with given value to the end of the DLL
        void append(int value);

        // delete last node
        void delete_last();
};

#endif // D_LINKED_LIST_H