#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"

class Binary_Search_Tree {    
    public:
        Node* root;

        // constructor
        Binary_Search_Tree();

        // print function
        void print() const;

        // insert a new node to the BST
        bool insert(const int value);

        // check if the value is in the BST
        bool contains(const int value) const;

    private:
        // get height of the BST
        int get_height(const Node* root) const;      
};

#endif // BINARY_SEARCH_TREE_H