#include <iostream>
#include "Node.h"
#include "D_Linked_List.h"

std::ostream &operator<<(std::ostream &os, const D_Linked_List *list) {
    os << "[ ";
    Node* current = list->head;
    while (current) {
        os << current->value;
        if (current->next != nullptr) {
            os << " <-> ";
        }
        current = current->next;
    }
    os << " ]" << std::endl;
    return os;
}


// constructor
D_Linked_List::D_Linked_List (int value) {
    Node* new_node = new Node(value);
    head = new_node;
    tail = new_node;
    length = 1;
}


// getters
void D_Linked_List::get_head() {
    std::cout << "Head: " << head->value << std::endl;
}

void D_Linked_List::get_tail() {
    std::cout << "Tail: " << tail->value << std::endl;
}

void D_Linked_List::get_length() {
    std::cout << "Length: " << length << std::endl;
}


// add a node with given value to the begginig of the DLL
void D_Linked_List::prepend(int value) {
    Node* new_node = new Node(value);
    // edge-case: empty list
    if (!head) {
        head = new_node;
        tail = new_node;
    // non-empty DLL
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    length++;
}


// add a node with given value to the end of the DLL
void D_Linked_List::append(int value) {
    Node* new_node = new Node(value);

    // edge case: DLL is empty
    if (!head) {
        head = new_node;
        tail = new_node;
    // non-empty DLL
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    length++;
}


// delete last node
void D_Linked_List::delete_last() {
    // edge case: empty DLL
    if (!head) return;

    // edge case: one node in a DLL
    Node* temp = tail;
    if (!head->next) {
        head = nullptr;
        tail = nullptr;
    // general case: DLL with two or more nodes
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}
