#include "Node.h"
#include <iostream>

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class Singly_Linked_List {
    friend std::ostream &operator<<(std::ostream &os, const Singly_Linked_List* head);

    private:
        Node* head;
        Node* tail;
        int length; 
   
    public:
        // constructor
        Singly_Linked_List(int value);

        // destructor
        ~Singly_Linked_List();

        // print SLL
        // is not used in main as I prefer overloading ostream operator<<
        void print_list();

        // ADDERS

        // add a node with the given value to the beginning of a SLL
        void prepend(int value);

        // add a new node with given value to the end of a SLL
        void append(int value);

        // insert a node with a particular value and index
        // inserting BEFORE given index
        bool insert(int index, int value);

        // DELETERS

        // delete the first node in a SLL
        void delete_first();

        // delete the last node from the SLL
        void delete_last();

        // delete a node at the particular index
        void delete_node(int index);

        // set the particular value to the particular node
        bool set(int index, int value);      

        // GETTERS
        
        void get_head();
        void get_tail();
        void get_length();

        // get the value of the node with this given index
        Node* get(int index);

        // reverse linked list in place
        void reverse();
};

#endif // SINGLY_LINKED_LIST_H