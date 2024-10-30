/***************************************************
 * File Test_Function.cpp include implimentations of 
 * the test functions for Doubly Linked List
 * data structure.
 * 
 * Prototypes for these functions can be found
 * in Test_Functions.cpp file
***************************************************/

#include <iostream>

#include "Node.h"
#include "D_Linked_List.h"
#include "Test_Functions.h"


// test add a node to the begging of the DLL
void test_prepend() {
    std::cout << "\n=== Prepend function test ===" << std::endl;

    D_Linked_List* dll_prep = new D_Linked_List(2);
    dll_prep->append(3);
    std::cout << dll_prep;

    dll_prep->prepend(1);
    std::cout << dll_prep;
}


// test add a node to the end of the DLL
void test_append() {
    std::cout << "\n=== Append function test ===" << std::endl;

    D_Linked_List* dll_app = new D_Linked_List(1);
    std::cout << dll_app;

    dll_app->append(2);
    std::cout << dll_app;

    dll_app->append(3);
    std::cout << dll_app;
}


// test insert function
// this function insert a node with a particular value 
// at a particular index
void test_insert() {
    std::cout << "\n=== Test Insert function ===" << std::endl;

    D_Linked_List* dll_insert = new D_Linked_List(1);
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
}


// test delete first node in the DLL
void test_delete_first() {
    std::cout << "\n=== Delete First function test ===" << std::endl;

    D_Linked_List* dll_del_first = new D_Linked_List(1);
    dll_del_first->append(2);
    std::cout << dll_del_first;

    dll_del_first->delete_first();
    std::cout << dll_del_first;

    dll_del_first->delete_first();
    std::cout << dll_del_first;

    dll_del_first->delete_first();
    std::cout << dll_del_first;
}


// test delete last node in the DLL
void test_delete_last() {
    std::cout << "\n=== Delete Last function test ==" << std::endl;

    D_Linked_List* dll_del_last = new D_Linked_List(1);
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
}


// test get function that return a value of the node
// of the given index
void test_get() {
    std::cout << "\n=== Test Get function ===" << std::endl;

    D_Linked_List* dll_get = new D_Linked_List(0);
    dll_get->append(1);
    dll_get->append(2);
    dll_get->append(3);
    std::cout << dll_get;

    for (int i = 0; i < 4; i++) {
        std::cout << "Index " << i << " value: " << dll_get->get(i)->value << std::endl;
    }
}

// test set function
// this function changes the value of the node with a particular index
void test_set() {
    std::cout << "\n=== Test Set function ===" << std::endl;

    D_Linked_List* dll_set = new D_Linked_List(11);
    dll_set->append(4);
    dll_set->append(23);
    dll_set->append(7);
    std::cout << dll_set << std::endl;

    for (int i = 0; i < 4; i++) {
        dll_set->set(i, i);
        std::cout << dll_set;
    }
}