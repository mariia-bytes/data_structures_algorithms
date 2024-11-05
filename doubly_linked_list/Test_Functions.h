/***************************************************
 * File Test_Function.h include test functions 
 * prototypes for Doubly Linked List
 * data structure.
 * 
 * Implementations of these prototypes can be found
 * in Test_Functions.cpp file
***************************************************/

// test constructor and operator<<
void test_constructor();

// test add a node to the begging of the DLL
void test_prepend();

// test add a node to the end of the DLL
void test_append();

// test insert function
// this function insert a node with a particular value 
// at a particular index
void test_insert();

// test delete first node in the DLL
void test_delete_first();

// test delete last node in the DLL
void test_delete_last();

// test delete node at a particular index
void test_delete_node();

// test get function that returns a value of the node
// of the given index
void test_get();

// test set function
// this function changes the value of the node with a particular index
void test_set();
