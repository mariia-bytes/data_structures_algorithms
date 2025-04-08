#include "Binary_Search_Tree.h"

// constructor
Binary_Search_Tree::Binary_Search_Tree() 
    : root(nullptr) {}


// prints the BST
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


// gets height of the tree - we need it only for print
int Binary_Search_Tree::get_height(const Node* root) const {
    if (root == nullptr) return 0;
    
    return std::max(get_height(root->left), get_height(root->right)) + 1;
}


// ITERATIVELY inserts a new node to the BST
bool Binary_Search_Tree::it_inserts(const int value) {
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

// helper function to RECURSIVELY insert a new node
void Binary_Search_Tree::r_inserts(const int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    root = r_inserts(root, value);
}

Node* Binary_Search_Tree::r_inserts(Node* current_node, const int value) {
    if (current_node == nullptr) return new Node(value);
    if (value < current_node->value) {
        current_node->left = r_inserts(current_node->left, value);
    } else if (value > current_node->value) {
        current_node->right = r_inserts(current_node->right, value);
    }
    return current_node;
}


// ITERATIVELY checks if the value is in the BST
bool Binary_Search_Tree::it_contains(const int value) const {
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


// helper function to RECURSIVELY check if the value is in the BST
bool Binary_Search_Tree::r_contains(const int value) const {
    return r_contains(root, value);
}


// RECURSIVELY checks if the value is in the BST
bool Binary_Search_Tree::r_contains(Node* current_node, const int value) const {
    // edge case: empty BST
    if (current_node == nullptr) return false;

    // edge case: one item in the BST
    if (current_node->value == value) return true;

    // if non of the above, traverse to the left
    if (value < current_node->value) {
        return r_contains(current_node->left, value);
    } else { // traverse to the right
        return r_contains(current_node->right, value);
    }
}


// helper function to delete a node
void Binary_Search_Tree::delete_node(const int value) {
    root = delete_node(root, value);
}


// recursively deletes node with a given value
Node* Binary_Search_Tree::delete_node(Node* current_node, const int value) {
    // if a node is not in the BST
    if (current_node == nullptr) return nullptr;
    if (value < current_node->value) {
        current_node->left = delete_node(current_node->left, value);
    } else if (value > current_node->value) {
        current_node->right = delete_node(current_node->right, value);
    // if a node is in the BST
    } else {
        // if the node is a leaf node
        if (current_node->left == nullptr && current_node->right == nullptr) {
            delete(current_node);
            return nullptr;
        // if the node is open on the left but has a node on the right
        } else if (current_node->left == nullptr) {
            Node* temp = current_node->right;
            delete(current_node);
            return temp;
        // if the node is open on the right but has a node on the left
        } else if (current_node->right == nullptr) {
            Node* temp = current_node->left;
            delete (current_node);
            return temp;
        // a node  has both left and right children
        } else {
            int sub_tree_min_value = min_value(current_node->right);
            current_node->value = sub_tree_min_value;
            current_node->right = delete_node(current_node->right, sub_tree_min_value);
        }
        
    }
    return current_node;
}


// looks for the minimum value in the sub tree
int Binary_Search_Tree::min_value(Node* current_node) {
    while (current_node->left) {
        current_node = current_node->left;
    }
    return current_node->value;
}


// breadth first search
void Binary_Search_Tree::breadth_first_search() {
    std::queue<Node*> q;
    q.push(root);

    while (q.size() > 0) {
        Node* current_node = q.front();
        q.pop();
        std::cout << current_node->value << " ";
        if (current_node->left) {
            q.push(current_node->left);
        }
        if (current_node->right) {
            q.push(current_node->right);
        }
    }
}


// helper function to DFS
void Binary_Search_Tree::dfs_pre_order() {
    dfs_pre_order(root);
}

// deapth first search pre order
void Binary_Search_Tree::dfs_pre_order(Node* current_node) {
    std::cout << current_node->value << " ";
    if (current_node->left) {
        dfs_pre_order(current_node->left);
    }
    if (current_node->right) {
        dfs_pre_order(current_node->right);
    }
}