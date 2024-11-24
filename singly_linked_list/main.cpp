#include "Node.h"
#include "Singly_Linked_List.h"
#include "Test.h"

int main() {

    // test SLL constructor and operator<<
    test_constructor();

    // test basic getters (all at once)
    test_getters();

    // test get a particular node function
    test_get();

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

    // test reverse
    test_reverse();
   
    return 0;
}