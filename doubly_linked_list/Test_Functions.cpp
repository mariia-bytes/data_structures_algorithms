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

    D_Linked_List* dll_1 = new D_Linked_List(1);
    std::cout << "\nDLL: " << dll_1;

}


// test add a node to the end of the DLL
void test_append() {
    std::cout << "\n=== Append function test ===" << std::endl;

    D_Linked_List* my_dll = new D_Linked_List(1);
    std::cout << "\nDLL: " << my_dll;

    my_dll->append(2);
    std::cout << my_dll;

    my_dll->append(3);
    std::cout << my_dll;
}