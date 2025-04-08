#include "Test.h"
#include "Heap.h"

void test_insert() {
    std::cout << "\n=== Test insert ===\n";
    Heap* heap_insert = new Heap();
    heap_insert->insert(99);
    heap_insert->insert(72);
    heap_insert->insert(61);
    heap_insert->insert(58);

    heap_insert->print_heap();

    heap_insert->insert(100);
    heap_insert->print_heap();

    heap_insert->insert(72);
    heap_insert->print_heap();

    delete heap_insert;
}

void test_remove() {
    std::cout << "\n=== Test remove ===\n";

    std::cout << "An empty heap: ";
    Heap* heap_remove = new Heap();
    heap_remove->remove();
    heap_remove->print_heap();

    std::cout << "Non empty heap: \n";
    heap_remove->insert(95);
    heap_remove->insert(75);
    heap_remove->insert(80);
    heap_remove->insert(55);
    heap_remove->insert(60);
    heap_remove->insert(50);
    heap_remove->insert(65);

    heap_remove->print_heap();

    heap_remove->remove();
    heap_remove->print_heap();

    heap_remove->remove();
    heap_remove->print_heap();

    delete heap_remove;
}