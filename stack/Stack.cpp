/*************************************************
 * This Stack.cpp include implimentations of the
 * member and friend functions of a Stack class
 * defined in Stack.h
*************************************************/

#include <iostream>
#include <climits>
#include "Node.h"
#include "Stack.h"

std::ostream &operator<<(std::ostream &os, const Stack* s) {
    os << "stack top->bottom:\n";
    Node* temp = s->top;
    while (temp) {
        os << "\t" << temp->value << std::endl;
        temp = temp->next;
    }
    return os;
}


 // constructor
Stack::Stack(int value) {
    Node* new_node = new Node(value);
    top = new_node;
    height = 1;
}

// destructor
Stack::~Stack() {
    Node* temp = top;
    while (top) { 
        top = top->next;
        delete temp;
        temp = top;
    }
}


// basic getters
void Stack::get_top() {
    std::cout << "Top: " << top->value << std::endl;
}

void Stack::get_height() {
    std::cout << "Height: " << height << std::endl;
}


// push (add) an item with a given value to a S
void Stack::push(int value) {
    Node* new_node = new Node(value);
    new_node->next = top;
    top = new_node;
    height++;
}


// pop (remove) top item from a S
int Stack::pop() {
    // edge case: empty Stack
    if (height == 0) return INT_MIN;
    
    Node* temp = top;
    int popped_value = top->value;
    top = top->next;
    delete temp;
    height--;

    return popped_value;
}