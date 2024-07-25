#include "Linked_List.h"
#include "Node.h"

#include <iostream>

// Overloading the ostream operator<< to work with LL
// print_list() can be used instead
std::ostream &operator<<(std::ostream &os, const Linked_List* list) {
    os << "[ ";
    Node* current = list->head;
    while (current) {
        os << current->value;
        if (current->next != nullptr) {
            os << " -> ";
        }
        current = current->next;
    }
    os << " ]" << std::endl;
    return os;
}

// Linked List constructor
Linked_List::Linked_List(int value) {
    Node* new_node = new Node(value);
    head = new_node;
    tail = new_node;
    length = 1;
}

// Linked List destructor
Linked_List::~Linked_List() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

// Print Linked List
// I don't use this function as I overloaded ostream operator<<
void Linked_List::print_list() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    } 
}

///////////// Additors / Insertors

// Add a node with given value to the beginning of the Linked List
void Linked_List::prepend(int value) {
    Node* new_node = new Node(value);
            
    // edge case: empty list
    if (!head) {
        head = new_node;
        tail = new_node;
    } else { // non-empty list
        new_node->next = head;
        head = new_node;
    }
    length++;
}

// Add new node with given value to the end of the Linked List
void Linked_List::append(int value) {
    Node* new_node = new Node(value);
    // edge case:: empty list
    if (!head) {
        head = new_node;
        tail = new_node;
    } else { // non-empty list
        tail->next = new_node;
        tail = new_node;
    }
    length++;
}

// Insert a node with a particular value and partuicular index
// inserting happens BEFORE given index
bool Linked_List::insert(int index, int value) {
    // check if the input index is OUT of range
    if (index < 0 || index > length) return false;

    // edge case: want to insert to the begginig of the list
    if (index == 0) {
        prepend(value);
        return true;
    }

    // edge case: want to insert to the end of the list
    if (index == length) {
        append(value);
        return true;
    }

    // general case: insert index somewhere in the middle
    Node* new_node = new Node(value);
    Node* temp = get(index - 1);
    new_node->next = temp->next;
    temp->next = new_node;
    length++;
    return true;
}


//////////////// Deletors

// Delete the first node in the Linked List
void Linked_List::delete_first() {
    // edge case: empty list
    if (!head) return;
            
    Node* temp = head;

    // edge case: only one node in the list
    if (head->next == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else { // non-empty list with more than one node
        head = head->next;
    }
    delete temp;
    length--;
}

// Delete the last node from the Linked List
void Linked_List::delete_last() {
    // edge case: empty list
    if (!head) return;

    Node* temp = head;

    // edge case: only one node in the list
    if (head->next == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else { // non-empty list with more than 1 node       
        Node* pre = head;
        while (temp->next != nullptr) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;    
    }           
    delete temp;
    length--;  
}

// Delete a node from the Linked List at the particular given index
void Linked_List::delete_node(int index) {
    // check if the input index is OUT of range
    if (index < 0 || index >= length) return;

    // edge case: delete first node in the Linked List
    if (index == 0) return delete_first();

    // edge case: delete the last node in the Linked List
    if (index == length - 1) return delete_last();

    // general case: delete a node somewhere in the middle of Linked List
    Node* prev = get(index - 1);
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
}

// Get the node from the Linked List with this given index
Node* Linked_List::get(int index) {
    // check if the input index is OUT of range
    if (index < 0 || index >= length) return nullptr;

    // if the index is IN range        
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

// Set the particular value to the particular node with the given index
bool Linked_List::set(int index, int value) {   
    Node* temp = get(index); // check the inout index if it's in range or not
    
    // if the given index is IN of range
    if (temp) {
        temp->value = value;
        return true;
    }

    // if the given index is OUT of range
    return false;
}

// Some basic setters of getters
// print the value of node to which the head is pointing 
// (the first node in the Linked List)
void Linked_List::get_head() {
    std::cout << "Head: " << head->value << std::endl;
}

// print the value of the node to which the tail is pointing 
// (the last node in the Linked List)
void Linked_List::get_tail() {
    std::cout << "Tail: " << tail->value << std::endl; 
}

// print the length oh the Linked List
void Linked_List::get_length() {
    std::cout << "Length: " << length << std::endl;
}


// Reverse Linked List IN PLACE
void Linked_List::reverse() {
    // switch head an tail
    Node* temp = head;
    head = tail;
    tail = temp;

    Node* before = nullptr;
    Node* after = temp->next;
    for (int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}