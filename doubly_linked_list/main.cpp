/****************************************************
 * This projest is to help me better understand what
 * Doubly Linked Lists are, how they are created and 
 * how to use them to solve different cases, 
 * including big amount of problems from LeetCode
****************************************************/
#include "Node.h"
#include "D_Linked_List.h"
#include "Test_Functions.h"

int main() {

    // creation of a DLL and checking operator<<
    D_Linked_List* my_dll = new D_Linked_List(1);
    std::cout << "\nDLL: " << my_dll;

    // test prepend function
    test_prepend();

    // test append function
    test_append();

    // test insert function
    // this function insert a node with a particular value 
    // at a particular index
    test_insert();

    // test delete_first function
    test_delete_first();

    // test delete_last function
    test_delete_last();

    // test delete_node function
    test_delete_node();

    // test get function
    // this function returns a value of the node of given index
    test_get();

    // test set function
    // this function changes the value of the node with a particular index
    test_set();

    return 0;
}