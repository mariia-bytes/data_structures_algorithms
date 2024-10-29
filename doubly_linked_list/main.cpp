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

    // test delete_last function
    std::cout << "\n=== Delete Last function test ==" << std::endl;
    // 3 items
    std::cout << my_dll;
    my_dll->delete_last();
    // 2 items left
    std::cout << my_dll;
    my_dll->delete_last();
    // 1 item left
    std::cout << my_dll;
    my_dll->delete_last();
    // o item left
    std::cout << my_dll;
    my_dll->delete_last();
    // just to be sure
    std::cout << my_dll;

    return 0;
}