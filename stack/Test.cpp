/***********************************************
 * This Test.cpp file includes implimentations
 * of the test functions targeted to test
 * Stack member functions for logical mistakes.
 * Definition of these test functions can be
 * found in Test.h file.
***********************************************/

#include <iostream>

#include "Node.h"
#include "Stack.h"
#include "Test.h"

// test Stack constructor and overloaded operator<<
void test_constructor() {
    std::cout << "\n=== Test Stack Constructor and operator<< ===\n" << std::endl;

    Stack* stack_constr = new Stack(1);
    std::cout << stack_constr;
    
    delete stack_constr;
}

// test basic getters
void test_getters() {
    std::cout << "\n=== Test basic Getters ===\n" << std::endl;

    Stack* stack_getters = new Stack(1);
    stack_getters->push(2);
    stack_getters->push(3);
    std::cout << stack_getters << std::endl;

    stack_getters->get_height();
    stack_getters->get_top();
}

// test push (add) member function
void test_push() {
    std::cout << "\n=== Test Push function ===\n" << std::endl;

    Stack* stack_push = new Stack(2);
    std::cout << stack_push << std::endl;

    stack_push->push(1);
    std::cout << stack_push << std::endl;

    delete stack_push;
}

// test pop (remove top item) member function
void test_pop() {
    std::cout << "\n=== Test Pop function ===\n" << std::endl;

    Stack* stack_pop = new Stack(1);
    std::cout << stack_pop;

    std::cout << "\nPopped value: " << stack_pop->pop() << std::endl;
    // check the edge case: empty Stack
    std::cout << "Popped value: " << stack_pop->pop();

    delete stack_pop;
}