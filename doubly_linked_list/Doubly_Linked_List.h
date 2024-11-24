/***************************************************************************
 * In this Dounbly_Linked_List.h file Doubly_Linked_List declared. 
 * Implementation of the class can be found in Doubly_Linked_List.cpp file.
***************************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "Node.h"

class Doubly_Linked_List {
    friend std::ostream &operator<<(std::ostream &os, const Doubly_Linked_List *list);
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        // constructor
        Doubly_Linked_List(const int value);

        // destructor
        ~Doubly_Linked_List();

        // basics getters
        void get_head() const;
        void get_tail() const;
        void get_length() const;

        // get function returns value of the node with given index
        Node* get(const int index) const;

        // add a node with given value to the begginig of the DLL
        void prepend(const int value);

        // add a node with given value to the end of the DLL
        void append(const int value);

        // add (insert) a node with a particular value at a particular index
        bool insert(const int index, const int value);

        // delete first node
        void delete_first();

        // delete last node
        void delete_last();

        // delete node at a particular index
        void delete_node(const int index);

        // change a value of the node of a particular index
        bool set(const int index, const int value);
};

#endif // DOUBLY_LINKED_LIST_H