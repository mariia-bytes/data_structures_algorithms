/*************************************************
 * This Queue.cpp include implimentations of the
 * member and friend functions of a Queue class
 * defined in Queue.h
*************************************************/

#include "Queue.h"
#include <climits>

std::ostream& operator<<(std::ostream& os, const Queue* queue) {
    os << "[ ";
    Node* temp = queue->first;
    while (temp) {
        os << temp->value;
        if (temp->next) {
            os << " -> ";
        }
        temp = temp->next;
    }
    os << " ]" << std::endl;
    return os;
}

// constructor
Queue::Queue(int value) {
    Node* new_node = new Node(value);
    first = new_node;
    last = new_node;
    length = 1;
}

// destuctor
Queue::~Queue() {
    Node* temp = first;
    while (first) {
        first = first->next;
        delete temp;
        temp = first;
    }
}


// basic getters
void Queue::get_first() const {
    std::cout << "First: " << first->value << std::endl;
}

void Queue::get_last() const {
    std::cout << "Last: " << last->value << std::endl;
}

void Queue::get_length() const {
    std::cout << "Length: " << length << std::endl;
}


// add an item to the end of a Q
void Queue::enqueue(const int value) {
    Node* new_node = new Node(value);
   
    // edge case: an empty Q
    if (!first) {
        first = new_node;
        last = new_node;
    } else { // non-empty Q
        last->next = new_node;
        last = new_node;
    }
    length++;
}


// remove the first item from the Q
int Queue::dequeue() {
    // edge case: empty Q
    if (!first) return INT_MIN;

    // edge case: one item in the Q
    Node* temp = first;
    int dequeued_value = first->value;
    if (!first->next) {
        first = nullptr;
        last = nullptr;
    } else { // for two or more items
        first = first->next;

    }
    delete temp;
    length--;
    
    return dequeued_value;
}