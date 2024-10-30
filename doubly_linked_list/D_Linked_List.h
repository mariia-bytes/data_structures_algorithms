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

        // basics getters
        void get_head();
        void get_tail();
        void get_length();

        // get function returns value of the node with given index
        Node* get(int index);

        // add a node with given value to the begginig of the DLL
        void prepend(int value);

        // add a node with given value to the end of the DLL
        void append(int value);

        // add (insert) a node with a particular value at a particular index
        bool insert(int index, int value);

        // delete first node
        void delete_first();

        // delete last node
        void delete_last();

        // change a value of the node of a particular index
        bool set(int index, int value);
};

#endif // D_LINKED_LIST_H