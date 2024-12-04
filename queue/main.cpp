#include "Queue.h"
#include "Test.h"

int main() {
    
    // test Queue constructor and overloading operator<<
    test_constructor();

    // test basic getters
    test_getters();

    // test enqueue
    test_enqueue();

    // test dequeue
    test_dequeue();

    return 0;
}