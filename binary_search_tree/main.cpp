#include "Binary_Search_Tree.h"
#include "Test.h"

int main() {
    // test BST constructor
    test_print();

    // test ITERATIVELY insert
    test_it_insert();

    // test RECURSIVELY insert
    test_r_insert();

    // test ITERATIVELY contains
    test_it_contains();

    // test RECURSIVELY contains
    test_r_contains();

    // test search for a minimum value
    test_min_value();

    // test delete a node
    test_delete();

    // test breadth first search
    test_bfs();

    // test deapth first search pre order
    test_dfs_pre_order();

    return 0;
}