#include <iostream>

#include "Test.h"
#include "Binary_Search_Tree.h"

// test BST constructor, get height and print
void test_print() {
    std::cout << "\n=== Test Constructor and Print ===\n" << std::endl;

    Binary_Search_Tree* bst_print = new Binary_Search_Tree();
    std::cout << bst_print->root << std::endl;

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
    // test insert
    bst_insert->insert(27);

    std::cout << "Last value inserted: " << bst_insert->root->left->right->value << std::endl;
}