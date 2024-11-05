/****************************************************
 * 
 * 
 * 
*****************************************************/

#include <iostream>

#include "Node.h"
#include "Stack.h"
#include "Test.h"

int main() {
    // test constructor and operator<<
    test_constructor();

    // test push member function
    test_push();

    // test pop member function
    test_pop();

    return 0;
}