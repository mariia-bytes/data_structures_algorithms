/*********************************************************************
 * This Doubly_Linked_List.cpp file includes implimentations of the 
 * member and friend functions of Doubly_Linked_List class.
 * Declaration of the Doubly_Linked_List class can be found in 
 * the Doubly_Linked_List.h file.
**********************************************************************/

#include <iostream>

#include "Node.h"
#include "Doubly_Linked_List.h"

std::ostream &operator<<(std::ostream &os, const Doubly_Linked_List *list) {
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
Doubly_Linked_List::Doubly_Linked_List (int value) {
    Node* new_node = new Node(value);
    head = new_node;
    tail = new_node;
    length = 1;
}

// destructor
Doubly_Linked_List::~Doubly_Linked_List() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}


// basic getters
void Doubly_Linked_List::get_head() {
    std::cout << "Head: " << head->value << std::endl;
}

void Doubly_Linked_List::get_tail() {
    std::cout << "Tail: " << tail->value << std::endl;
}

void Doubly_Linked_List::get_length() {
    std::cout << "Length: " << length << std::endl;
}

// get the value of the node with given index
Node* Doubly_Linked_List::get (int index) {
    // edge cases: index is out of range
    if (index < 0 || index >= length) return nullptr;
    // if index is in range
    Node* temp = head;
    // if index is in first half of the list
    if (index < length/2) {
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    // if index is in the second half of the list
    } else {
        temp = tail;
        for (int i = length - 1; i > index; i--) {
            temp = temp->prev;
        }
    }
    return temp;
}


// change a value of the node with a particular index
bool Doubly_Linked_List::set(int index, int value) {
    Node* temp = get(index); // already has optimization - cool, uh?
    if (temp) {
        temp->value = value;
        return true;
    }
    return false;
}


// add a node with given value to the begginig of the DLL
void Doubly_Linked_List::prepend(int value) {
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
void Doubly_Linked_List::append(int value) {
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


// add (insert) a node with a particular value to a particular index
bool Doubly_Linked_List::insert(int index, int value) {
    // check if the index is out of range
    if (index < 0 || index > length) return false;
    // if the index is 0 => begginig od the DLL
    if (index == 0) {
        prepend(value);
        return true;
    }
    // if the index is equal to the end of the DLL
    if (index == length) {
        append(value);
        return true;
    }
    // if the node should be inserted somewhere in the middle of the DLL
    Node* new_node = new Node(value);
    Node* before = get(index - 1); // get function is O(n)
    Node* after = before->next; // that way it's O(1);
    new_node->prev = before;
    new_node->next = after;
    before->next = new_node;
    after->prev = new_node;
    
    length++;
    return true;
}


// delete first node
void Doubly_Linked_List::delete_first() {
    // edge case: empty DLL
    if (!head) return;
    // edge case: one node in DLL
    Node* temp = head;
    if (!head->next) {
        head = nullptr;
        tail = nullptr;
    // DLL with two or more nodes
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
}


// delete last node
void Doubly_Linked_List::delete_last() {
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


// delete node at a particular index
void Doubly_Linked_List::delete_node(int index) {
    // covering out-of-range-index situation
    if (index < 0 || index >= length) return;
    // removing the first node
    if (index == 0) return delete_first();
    // removing the last element
    if (index == length - 1) return delete_last();
    
    // removing the node somethere in the middle of DLL
    Node* temp = get(index);
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    length--;
}