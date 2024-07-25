#include "Node.h"
#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Linked_List {
    friend std::ostream &operator<<(std::ostream &os, const Linked_List* head);

    private:
        Node* head;
        Node* tail;
        int length; 
   
    public:
        // constructor
        Linked_List(int value);

        // destructor
        ~Linked_List();

        // print linked list
        // is not used in main as I prefer overloading ostream operator<<
        void print_list();

        // add a new node with given value to the end of the list
        void append(int value);

        // delete the last node from the list
        void delete_last();

        // add a node with the given value to the beginning of the list
        void prepend(int value);

        // delete the first node in the list
        void delete_first();

        // delete a node at the particular index
        void delete_node(int index);

        // get the value of the node with this given index
        Node* get(int index);

        // set the particular value to the particular node
        bool set(int index, int value);

        // insert a node with a particular value and index
        // inserting BEFORE given index
        bool insert(int index, int value);

        // basic setters of getters
        // print the value of the head
        void get_head();

        // print the value of the tail
        void get_tail();

        // print the length of the linked list
        void get_length();

        // reverse linked list in place
        void reverse();
};

#endif // LINKED_LIST_H