/*************************************************************
 * This Test.h includes implimentation of the functions
 * testing the member and friend functions of the 
 * Singly Linkled List class. 
 * The declarations of these functions can be found in 
 * Test.cpp file.
*************************************************************/

#include <iostream>

#include "Singly_Linked_List.h"
#include "Test.h"

// test constructor of the SLL and overloaded operator<<
void test_constructor() {
    std::cout << "\n=== Test constructor and operator<< ===\n" << std::endl;
  
    Singly_Linked_List* sll_constr = new Singly_Linked_List(2);
    std::cout << sll_constr;

    delete sll_constr;
}

// test prepend function
void test_prepend() {
    std::cout << "\n=== Test Prepend function ===\n" << std::endl;

    Singly_Linked_List* sll_prepend = new Singly_Linked_List(2);
    std::cout << sll_prepend;

    sll_prepend->prepend(1);
    std::cout << sll_prepend;

    delete sll_prepend;
}

// test append function
void test_append() {
    std::cout << "\n=== Test Append function ===\n" << std::endl;

    Singly_Linked_List* sll_append = new Singly_Linked_List(1);
    std::cout << sll_append;

    sll_append->append(2);
    std::cout << sll_append;

    delete sll_append;
}

// test insert function
void test_insert() {
    std::cout << "\n=== Test Insert function ===\n" << std::endl;

    Singly_Linked_List* sll_insert = new Singly_Linked_List(1);
    sll_insert->append(3);
    std::cout << sll_insert;

    sll_insert->insert(1,2);
    std::cout << sll_insert;

    sll_insert->insert(-10,5);
    std::cout << sll_insert;

    // this is ineresting, for some reason it doesn't work
    sll_insert->insert(0,0);
    std::cout << sll_insert;

    delete sll_insert;
}

// test delete first function
void test_delete_first() {
    std::cout << "\n=== Test Delete First function ===\n" << std::endl;

    Singly_Linked_List* sll_delete_first = new Singly_Linked_List(1);
    sll_delete_first->append(2);
    std::cout << sll_delete_first;

    sll_delete_first->delete_first();
    std::cout << sll_delete_first;

    sll_delete_first->delete_first();
    std::cout << sll_delete_first;

    sll_delete_first->delete_first();
    std::cout << sll_delete_first;

    delete sll_delete_first;
}

// test delete last function
void test_delete_last() {
    std::cout << "\n=== Test Delete Last function ===\n" << std::endl;

    Singly_Linked_List* sll_delete_last = new Singly_Linked_List(1);
    sll_delete_last->append(2);
    std::cout << sll_delete_last;

    sll_delete_last->delete_last();
    std::cout << sll_delete_last;

    sll_delete_last->delete_last();
    std::cout << sll_delete_last;

    sll_delete_last->delete_last();
    std::cout << sll_delete_last;

    delete sll_delete_last;
}

// test delete function (delete a node somewhere in the middle)
void test_delete_node() {
    std::cout << "\n=== Test Delete Node function ===\n" << std::endl;

    Singly_Linked_List* sll_delete = new Singly_Linked_List(1);
    sll_delete->append(2);
    sll_delete->append(3);
    std::cout << sll_delete;

    sll_delete->delete_node(1);
    std::cout << sll_delete;

    sll_delete->delete_node(1);
    std::cout << sll_delete;

    sll_delete->delete_node(0);
    std::cout << sll_delete;

    sll_delete->delete_node(-10);
    std::cout << sll_delete;

    delete sll_delete;
}

// test get function
void test_get() {
    std::cout << "\n=== Test Get function ===\n" << std::endl;

    Singly_Linked_List* sll_get = new Singly_Linked_List(1);
    sll_get->append(2);
    sll_get->append(3);
    std::cout << sll_get;

    std::cout << "Head value: " << sll_get->get(0)->value << std::endl;
    std::cout << "Middle value: " << sll_get->get(1)->value << std::endl;
    sll_get->get(-100)->value;

    delete sll_get;
}