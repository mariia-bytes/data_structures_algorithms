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

// test ITERATIVELY insert
void test_it_insert() {
    std::cout << "\n=== Test ITERATIVELY Insert ===\n" << std::endl;

    Binary_Search_Tree* bst_it_insert = new Binary_Search_Tree();

    bst_it_insert->it_inserts(47);
    bst_it_insert->it_inserts(21);
    bst_it_insert->it_inserts(76);
    bst_it_insert->it_inserts(18);
    bst_it_insert->it_inserts(52);
    bst_it_insert->it_inserts(82);
    bst_it_insert->it_inserts(27);
    
    bst_it_insert->print();

    delete bst_it_insert;
}

// test RECURSIVELY insert
void test_r_insert() {
    std::cout << "\n=== Test RECURSIVELY Insert ===\n" << std::endl;

    Binary_Search_Tree* bst_r_insert = new Binary_Search_Tree();

    bst_r_insert->r_inserts(47);
    bst_r_insert->r_inserts(21);
    bst_r_insert->r_inserts(76);
    bst_r_insert->r_inserts(18);
    bst_r_insert->r_inserts(52);
    bst_r_insert->r_inserts(82);
    bst_r_insert->r_inserts(27);
    
    bst_r_insert->print();

    delete bst_r_insert;
}

// test ITERATIVELY contains
void test_it_contains() {
    std::cout << "\n=== Test ITERATIVELY Contains ===\n" << std::endl;

    Binary_Search_Tree* bst_it_contains = new Binary_Search_Tree();

    bst_it_contains->it_inserts(67);
    bst_it_contains->it_inserts(11);
    bst_it_contains->it_inserts(6);
    bst_it_contains->it_inserts(98);
    bst_it_contains->it_inserts(42);
    bst_it_contains->it_inserts(2);
    bst_it_contains->it_inserts(17);
    
    bst_it_contains->print();

    std::cout << std::boolalpha;

    std::cout << "\nContains 17: " << bst_it_contains->it_contains(17) << std::endl;
    std::cout << "Contains 77: " << bst_it_contains->it_contains(77) << std::endl;

    delete bst_it_contains;

}


// test RECURSIVELY contains
void test_r_contains() {
    std::cout << "\n=== Test RECURSIVELY Contains ===\n" << std::endl;

    Binary_Search_Tree* bst_r_contains = new Binary_Search_Tree();

    bst_r_contains->it_inserts(67);
    bst_r_contains->it_inserts(11);
    bst_r_contains->it_inserts(6);
    bst_r_contains->it_inserts(98);
    bst_r_contains->it_inserts(42);
    bst_r_contains->it_inserts(2);
    bst_r_contains->it_inserts(17);
    
    bst_r_contains->print();

    std::cout << std::boolalpha;

    std::cout << "\nContains 17: " << bst_r_contains->r_contains(17) << std::endl;
    std::cout << "Contains 77: " << bst_r_contains->r_contains(77) << std::endl;

    delete bst_r_contains;

}


// test search for a minimum value
void test_min_value() {
    std::cout << "\n=== Test Min Value ===\n" << std::endl;

    Binary_Search_Tree* bst_min_value = new Binary_Search_Tree();

    bst_min_value->it_inserts(44);
    bst_min_value->it_inserts(13);
    bst_min_value->it_inserts(60);
    bst_min_value->it_inserts(9);
    bst_min_value->it_inserts(6);
    bst_min_value->it_inserts(22);
    bst_min_value->it_inserts(77);
    
    bst_min_value->print();

    std::cout << "\nMinimum value from the root: " << bst_min_value->min_value(bst_min_value->root) << "\n";
    std::cout << "\nMinimum value from the root->right: " << bst_min_value->min_value(bst_min_value->root->right) << "\n";

    delete bst_min_value;
}


// test search for a minimum value
void test_delete() {
    std::cout << "\n=== Test Delete ===\n" << std::endl;

    Binary_Search_Tree* bst_delete = new Binary_Search_Tree();

    std::cout << "Delete on an empty tree: \n";
    bst_delete->delete_node(1);

    std::cout << "\nNon-empty tree: \n";
    bst_delete->r_inserts(2);
    bst_delete->r_inserts(1);
    bst_delete->r_inserts(3);
    bst_delete->print();

    std::cout << "After deleting the root(2)\n";
    bst_delete->delete_node(2);
    bst_delete->print();

    delete bst_delete;
}

// test breadth first search
void test_bfs() {
    std::cout << "\n=== Test Breadth First Tree ===\n" << std::endl;

    Binary_Search_Tree* bst_bfs = new Binary_Search_Tree();

    bst_bfs->it_inserts(47);
    bst_bfs->it_inserts(21);
    bst_bfs->it_inserts(76);
    bst_bfs->it_inserts(18);
    bst_bfs->it_inserts(28);
    bst_bfs->it_inserts(52);
    bst_bfs->it_inserts(82);

    bst_bfs->print();

    std::cout << "\n";

    bst_bfs->breadth_first_search();

    delete bst_bfs;
}


// test deapth first search pre order
void test_dfs_pre_order() {
    std::cout << "\n=== Test Deapth First Tree Pre Order ===\n" << std::endl;

     Binary_Search_Tree* bst_dfs_pre_order = new Binary_Search_Tree();

    bst_dfs_pre_order->it_inserts(47);
    bst_dfs_pre_order->it_inserts(21);
    bst_dfs_pre_order->it_inserts(76);
    bst_dfs_pre_order->it_inserts(18);
    bst_dfs_pre_order->it_inserts(28);
    bst_dfs_pre_order->it_inserts(52);
    bst_dfs_pre_order->it_inserts(82);

    bst_dfs_pre_order->print();

    std::cout << "\n";

    bst_dfs_pre_order->dfs_pre_order();

    delete bst_dfs_pre_order;
}