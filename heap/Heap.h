#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <optional>

class Heap {
private:
    std::vector<int> heap;

    // returns the index of the left child
    int left_child(const int index) const;

    // returns the index of the right child
    int right_child(const int index) const;

    // returns the index of the parent
    int parent(const int index) const;

    // swaps the values of two gived indexes
    void swap(const int index_1, const int index_2);

    void sink_down(int index);

public:
    // prints the heap
    void print_heap();

    // inserts an item with the given value into the heap
    void insert(const int value);

    // removes the top vertex
    std::optional<int> remove();
};

#endif // HEAP_H