/***************************************************
 * File Test.cpp includes implementations of 
 * the test functions for Doubly Linked List
 * data structure.
 * 
 * Prototypes for these functions can be found
 * in Test.cpp file
***************************************************/

#include <iostream>

#include "Node.h"
#include "Doubly_Linked_List.h"
#include "Test.h"


// test constructor and operator<<
void test_constructor() {
    std::cout << "\n=== Test Constructor and Operator<< ===\n" << std::endl;

    Doubly_Linked_List* my_dll = new Doubly_Linked_List(1);
    std::cout << "\nDLL: " << my_dll;
    
    delete my_dll;
}


// test add a node to the begging of the DLL
void test_prepend() {
    std::cout << "\n=== Test Prepend function ===\n" << std::endl;

    Doubly_Linked_List* dll_prep = new Doubly_Linked_List(2);
    dll_prep->append(3);
    std::cout << dll_prep;

    dll_prep->prepend(1);
    std::cout << dll_prep;

    delete dll_prep;
}


// test add a node to the end of the DLL
void test_append() {
    std::cout << "\n=== Test Append function ===\n" << std::endl;

    Doubly_Linked_List* dll_app = new Doubly_Linked_List(1);
    std::cout << dll_app;

    dll_app->append(2);
    std::cout << dll_app;

    dll_app->append(3);
    std::cout << dll_app;

    delete dll_app;
}


// test insert function
// this function insert a node with a particular value 
// at a particular index
void test_insert() {
    std::cout << "\n=== Test Insert function ===\n" << std::endl;

    Doubly_Linked_List* dll_insert = new Doubly_Linked_List(1);
    dll_insert->append(3);
    std::cout << dll_insert << std::endl;

    dll_insert->insert(1,2);
    std::cout << dll_insert;

    dll_insert->insert(0, 0); // edge case: prepend
    std::cout << dll_insert;

    dll_insert->insert(4, 4); // edge case: append
    std::cout << dll_insert;

    std::cout << std::endl;
    dll_insert->insert(-9, 3); // invalid case
    std::cout << dll_insert;

    delete dll_insert;
}


// test delete first node in the DLL
void test_delete_first() {
    std::cout << "\n=== Test Delete First function ===\n" << std::endl;

    Doubly_Linked_List* dll_del_first = new Doubly_Linked_List(1);
    dll_del_first->append(2);
    std::cout << dll_del_first;

    dll_del_first->delete_first();
    std::cout << dll_del_first;

    dll_del_first->delete_first();
    std::cout << dll_del_first;

    dll_del_first->delete_first();
    std::cout << dll_del_first;

    delete dll_del_first;
}


// test delete last node in the DLL
void test_delete_last() {
    std::cout << "\n=== Test Delete Last function ===\n" << std::endl;

    Doubly_Linked_List* dll_del_last = new Doubly_Linked_List(1);
    dll_del_last->append(2);
    dll_del_last->append(3);

    // 3 items
    std::cout << dll_del_last;
    dll_del_last->delete_last();
    // 2 items left
    std::cout << dll_del_last;
    dll_del_last->delete_last();
    // 1 item left
    std::cout << dll_del_last;
    dll_del_last->delete_last();
    // o item left
    std::cout << dll_del_last;
    dll_del_last->delete_last();
    // just to be sure
    std::cout << dll_del_last;

    delete dll_del_last;
}


// test delete node at a particular index
void test_delete_node() {
    std::cout << "\n=== Test Delete Node function ===\n" << std::endl;

    Doubly_Linked_List* dll_del_node = new Doubly_Linked_List(0);
    dll_del_node->append(1);
    dll_del_node->append(2);
    dll_del_node->append(3);
    std::cout << dll_del_node << std::endl;

    dll_del_node->delete_node(1);
    std::cout << dll_del_node;

    dll_del_node->delete_node(0);
    std::cout << dll_del_node;

    dll_del_node->delete_node(1);
    std::cout << dll_del_node;

    dll_del_node->delete_node(-10);
    std::cout << dll_del_node;

    delete dll_del_node;
}


// test get function that return a value of the node
// of the given index
void test_get() {
    std::cout << "\n=== Test Get function ===\n" << std::endl;

    Doubly_Linked_List* dll_get = new Doubly_Linked_List(0);
    dll_get->append(1);
    dll_get->append(2);
    dll_get->append(3);
    std::cout << dll_get;

    for (int i = 0; i < 4; i++) {
        std::cout << "Index " << i << " value: " << dll_get->get(i)->value << std::endl;
    }

    delete dll_get;
}

// test set function
// this function changes the value of the node with a particular index
void test_set() {
    std::cout << "\n=== Test Set function ===\n" << std::endl;

    Doubly_Linked_List* dll_set = new Doubly_Linked_List(11);
    dll_set->append(4);
    dll_set->append(23);
    dll_set->append(7);
    std::cout << dll_set << std::endl;

    for (int i = 0; i < 4; i++) {
        dll_set->set(i, i);
        std::cout << dll_set;
    }

    delete dll_set;
}