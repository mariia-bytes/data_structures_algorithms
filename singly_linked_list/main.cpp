/****************************************************
 * This projest is to help me better understand what
 * Single Linked Lists are, how they are created and 
 * how to use them to solve different cases, 
 * including big amount of problems from LeetCode
****************************************************/

#include <iostream>

#include "Node.h"
#include "Singly_Linked_List.h"
#include "Test.h"


int main() {

    // test SLL constructor and operator<<
    test_constructor();

    // test prepend function
    test_prepend();

    // test append function 
    test_append();

    // test insert function
    test_insert();

    // test_ delete first
    test_delete_first();

    // test delete last
    test_delete_last();

    // test delete a node somewhere in the middle
    test_delete_node();


    
    return 0;
}