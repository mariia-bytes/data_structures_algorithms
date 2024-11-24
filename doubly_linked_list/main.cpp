#include "Node.h"
#include "Doubly_Linked_List.h"
#include "Test.h"

int main() {

    // test constructor and operator<<
    test_constructor();

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