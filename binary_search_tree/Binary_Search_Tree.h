#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>

class Binary_Search_Tree {    
    public:
        Node* root;

        // constructor
        Binary_Search_Tree();

        // prints the BST
        void print() const;

        // ITERATIVELY inserts a new node
        bool it_inserts(const int value);

        // ITERATIVELY checks if the value is in the BST
        bool it_contains(const int value) const;

        // helper function to RECURSIVELY insert a new node
        void r_inserts(const int value);

        // helper function to RECURSIVELY check if the value is in the BST
        bool r_contains(const int value) const;

        // helper function to delete a node
        void delete_node(const int value);

        // looks for the minimum value in the sub-tree
        int min_value(Node* current_node);

        // breadth first search
        void breadth_first_search();

        // helper function to DFS
        void dfs_pre_order();

    private:
        // get height of the BST
        int get_height(const Node* root) const;

        // RECURSIVELY inserts a new node
        Node* r_inserts(Node* current_node, const int value);

        // RECURSIVELY checks if the value is in the BST
        bool r_contains(Node* current_node, const int value) const;

        // recursively deletes node with a given value
        Node* delete_node(Node* current_node, const int value);

        // deapth first search pre order
        void dfs_pre_order(Node* current_node);
};

#endif // BINARY_SEARCH_TREE_H