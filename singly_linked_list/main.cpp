/****************************************************
 * This projest is to help me better understand what
 * Single Linked Lists are, how they are created and 
 * how to use them to solve different cases, 
 * including big amount of problems from LeetCode
****************************************************/

#include <iostream>
#include <iomanip>

#include "Node.h"
#include "Singly_Linked_List.h"


int main() {

    // Checking the creation of the LL and its communication with ostream operator<<
    Singly_Linked_List* ll_1 = new Singly_Linked_List(2);
    std::cout << "Created LL with one Node: " << ll_1 << std::endl;
    
    // Checking adding a Node to the beginnig of the SLL
    ll_1->prepend(1);
    std::cout << "Added a new Node to the beginning of the SLL: " << ll_1 << std::endl;
    
    // Checking adding a Node to the end of the SLL
    ll_1->append(3);
    std::cout << "Added a new Node to the end of the SLL: " << ll_1 << std::endl;

    // Cheching adding a Node to a particular index
    ll_1->insert(1, 20);
    std::cout << "To the index [1] added a new node with value 20: " << ll_1 << std::endl;


    // Checking how good delete_node() member works with all cases
    std::cout << "\n===== Test delete_node with all edge cases =====\n" << std::endl;

    Singly_Linked_List* ll_2 = new Singly_Linked_List(1);
    ll_2->append(2);
    ll_2->append(3);
    ll_2->append(4);
    ll_2->append(5);
    
    unsigned int width = 45;
    std::cout << std::setw(width) << std::left 
              << "SLL before delete_node: " 
              << ll_2 << std::endl;

    ll_2->delete_node(2);
    std::cout << std::setw(width) << std::left 
              << "SLL after delete_node in the middle: " 
              << ll_2 << std::endl;

    ll_2->delete_node(0);
    std::cout << std::setw(width) << std::left 
              << "SLL after delete_node of the first node: " 
              << ll_2 << std::endl;

    ll_2->delete_node(2);
    std::cout << std::setw(width) << std::left 
              << "SLL after delete_node of the last node: " 
              << ll_2 << std::endl;

    // Checking reverse() method
    std::cout << "\n===== Test reverse method =====\n" << std::endl;
    
    Singly_Linked_List* ll_3 = new Singly_Linked_List(10);
    ll_3->append(20);
    ll_3->append(30);
    ll_3->append(40);

    width = 25;

    std::cout << std::setw(width) << std::left 
              << "LL before reverse(): " 
              << ll_3 << std::endl;
    ll_3->reverse();
    std::cout << std::setw(width) << std::left
              << "LL after reverse(): " 
              << ll_3 << std::endl;

    delete ll_1;
    delete ll_2;
    delete ll_3;

    return 0;
}