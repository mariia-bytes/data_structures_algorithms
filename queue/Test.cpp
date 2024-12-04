/***********************************************
 * This Test.cpp file includes implimentations
 * of the test functions targeted to test
 * Queue member functions for logical mistakes.
 * Definition of these test functions can be
 * found in Test.h file.
***********************************************/
#include <iostream>

#include "Test.h"
#include "Node.h"
#include "Queue.h"

// test constructor and operator<<
void test_constructor() {
    std::cout << "\n=== Test constructor ===\n" << std::endl;

    Queue* q_constructor = new Queue(1);
    std::cout << q_constructor;

    delete q_constructor;
}


// test basic getters
void test_getters() {
    std::cout << "\n=== Test basic getters ===\n" << std::endl;

    Queue* q_getters = new Queue(10);
    std::cout << q_getters << std::endl;

    q_getters->get_first();
    q_getters->get_last();
    q_getters->get_length();

    delete q_getters;
}


// test enqueue
void test_enqueue() {
    std::cout << "\n=== Test Enqueue ===\n" << std::endl;

    Queue* q_enqueue = new Queue(1);
    std::cout << q_enqueue;

    q_enqueue->enqueue(2);
    std::cout << q_enqueue;

    delete q_enqueue;
}


// test dequeue
void test_dequeue() {
    std::cout << "\n=== Test Dequeue ===\n" << std::endl;

    Queue* q_dequeue = new Queue(1);
    q_dequeue->enqueue(2);
    std::cout << q_dequeue << std::endl;

    q_dequeue->dequeue();
    std::cout << q_dequeue;

    q_dequeue->dequeue();
    std::cout << q_dequeue;

    q_dequeue->dequeue();
    std::cout << q_dequeue;

    delete q_dequeue;
}