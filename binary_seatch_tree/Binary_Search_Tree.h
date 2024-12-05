#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"

class Binary_Search_Tree {    
    public:
        Node* root;

        // constructor
        Binary_Search_Tree();

        // print function
        void print();

        // insert a new node to the BST
        bool insert(int value);

    private:
        // get height of the BST
        int get_height(Node* root);
};

#endif // BINARY_SEARCH_TREE_H