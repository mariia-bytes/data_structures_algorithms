#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>

#include "Binary_Search_Tree.h"

// constructor
Binary_Search_Tree::Binary_Search_Tree() 
    : root(nullptr) {}


// print the BST
void Binary_Search_Tree::print() const {
    if (root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
    } else {
        int height = get_height(root);
        int max_nodes = std::pow(2, height) - 1;
        int max_wigth = max_nodes * 4;

        std::queue<Node*> q;
        q.push(root);

        for (int i {1}; i <= height; i++) {
            int level_nodes = std::pow(2, i - 1);
            int space_between_nodes = max_wigth / level_nodes;
            int current_node_count = 0;

            while (current_node_count < level_nodes) {
                Node* node = q.front();
                q.pop();

                if (current_node_count == 0) {
                    std::cout << std::setw(space_between_nodes / 2);
                } else {
                    std::cout << std::setw(space_between_nodes);
                }

                if (node) {
                    std::cout << node->value;
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    std::cout << " ";
                    q.push(nullptr);
                    q.push(nullptr);
                }

                current_node_count++;
            }
            std::cout << std::endl;
        }
    }
}


// get height of the tree - we need it only for print
int Binary_Search_Tree::get_height(const Node* root) const {
    if (root == nullptr) return 0;
    
    return std::max(get_height(root->left), get_height(root->right)) + 1;
}


// insert a new node to the BST
bool Binary_Search_Tree::insert(const int value) {
    Node* new_node = new Node(value);
    // empty BST
    if (root == nullptr) {
        root = new_node;
        return true;
    }
    // non-empty BST
    Node* temp = root;
    while (true) {
        // values are not allowed to be equal in BST
        if (new_node->value == temp->value) return false;
        // if the value of a new_node is not equal to one of the exisited nodes
        // first we work with the left side of the BST
        if (new_node->value < temp->value) {
            // if the place on the left of the temp is open
            if (temp->left == nullptr) {
                temp->left = new_node;
                return true;
            }
            // if the place isn't open
            temp = temp->left;
        // now we work with the right side of the BST
        } else {
            // if the place on the right side of the temp is open
            if (temp->right == nullptr) {
                temp->right = new_node;
                return true;
            }
            // if the place isn't open
            temp = temp->right;
        }
    }
}


bool Binary_Search_Tree::contains(const int value) const {
    // empty BST
    // if (root == nullptr) return false;
    // but the harsh truth is, you don't need this edge case handling explicitly

    // non-empty BST
    Node* temp = root;
    while (temp) {
        if (value < temp->value) {
            temp = temp->left;
        } else if (value > temp->value) {
            temp = temp->right;
        } else { // value = temp->value
            return true;
        }
    }
    return false;
}