/*********************************************************************
 * This Singly_Linked_List.cpp file includes implementations of the 
 * member and friend functions of Singly_Linked_List class.
 * Declaration of the Singly_Linked_List class can be found in 
 * the Singly_Linked_List.h file.
**********************************************************************/

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include "Node.h"

class Singly_Linked_List {
    friend std::ostream &operator<<(std::ostream &os, const Singly_Linked_List* head);

    private:
        Node* head;
        Node* tail;
        int length; 
   
    public:
        // constructor
        Singly_Linked_List(const int value);

        // destructor
        ~Singly_Linked_List();

        // print SLL
        // is not used in main as I prefer overloading ostream operator<<
        void print_list() const;

        // ADDERS

        // add a node with the given value to the beginning of a SLL
        void prepend(const int value);

        // add a new node with given value to the end of a SLL
        void append(const int value);

        // insert a node with a particular value and index
        // inserting BEFORE given index
        bool insert(const int index, const int value);

        // DELETERS

        // delete the first node in a SLL
        void delete_first();

        // delete the last node from the SLL
        void delete_last();

        // delete a node at the particular index
        void delete_node(const int index);

        // set the particular value to the particular node
        bool set(const int index, const int value);      

        // GETTERS
        
        void get_head() const;
        void get_tail() const;
        void get_length() const;

        // get the value of the node with this given index
        Node* get(const int index) const;

        // reverse linked list in place
        void reverse();
};

#endif // SINGLY_LINKED_LIST_H