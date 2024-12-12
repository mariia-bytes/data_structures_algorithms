#include <iostream>

#include "Test.h"
#include "Binary_Search_Tree.h"

// test BST constructor, get height and print
void test_print() {
    std::cout << "\n=== Test Constructor and Print ===\n" << std::endl;

    Binary_Search_Tree* bst_print = new Binary_Search_Tree();
    std::cout << bst_print->root << std::endl;

    delete bst_print;
}

// test insert
void test_insert() {
    std::cout << "\n=== Test Insert ===\n" << std::endl;

    Binary_Search_Tree* bst_insert = new Binary_Search_Tree();

    bst_insert->insert(47);
    bst_insert->insert(21);
    bst_insert->insert(76);
    bst_insert->insert(18);
    bst_insert->insert(52);
    bst_insert->insert(82);
    bst_insert->insert(27);
    
    bst_insert->print();

    delete bst_insert;
}


// test contains
void test_contains() {
    std::cout << "\n=== Test Contains ===\n" << std::endl;

    Binary_Search_Tree* bst_contains = new Binary_Search_Tree();

    bst_contains->insert(67);
    bst_contains->insert(11);
    bst_contains->insert(6);
    bst_contains->insert(98);
    bst_contains->insert(42);
    bst_contains->insert(2);
    bst_contains->insert(17);
    
    bst_contains->print();

    std::cout << std::boolalpha;

    std::cout << "\nContains 17: " << bst_contains->contains(17) << std::endl;
    std::cout << "Contains 77: " << bst_contains->contains(77) << std::endl;

    delete bst_contains;

}