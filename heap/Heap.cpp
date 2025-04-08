#include "Heap.h"

// returns the index of the left child
int Heap::left_child(const int index) const  {
    return 2 * index + 1;
}

// returns the index of the right child
int Heap::right_child(const int index) const {
    return 2 * index + 2;
}

// returns the index of the parent
int Heap::parent(const int index) const {
    return (index - 1)/2;
}

// swaps the values of two gived indexes
void Heap::swap(const int index_1, const int index_2) {
    int& a = heap[index_1];
    int& b = heap[index_2];
    std::swap(a, b);
}

void Heap::sink_down(int index) {
    int max_index = index;
    while (true) {
        int left_index = left_child(index);
        int right_index = right_child(index);
        if (left_index <heap.size() && heap.at(left_index) > heap.at(max_index)) {
            max_index = left_index;
        }
        if (right_index < heap.size() && heap.at(right_index) > heap.at(max_index)) {
            max_index = right_index;
        }
        if (max_index != index) {
            swap(max_index, index);
            index = max_index;
        } else {
            return;
        }
    }
}

// prints the heap
void Heap::print_heap() {
    std::cout << "\n[";
    for (int i = 0; i < heap.size(); i++) {
        std::cout << heap.at(i);
        if (i < heap.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

//inserts an item into the heap
void Heap::insert(const int value) {
    heap.push_back(value);
    int current = heap.size() - 1;

    while (current > 0 && heap.at(current) > heap.at(parent(current))) {
        swap(current, parent(current));
        current = parent(current);
    }
}

// removes the top vertex
std::optional<int> Heap::remove() {
    // edge case: empty heap
    if (heap.empty()) {
        return std::nullopt;
    }
    int max_value = heap.front();

    // edge case: one item in the heap
    if (heap.size() == 1) {
        heap.pop_back();
    } else { // general case of two or more items
        heap.at(0) = heap.back();
        heap.pop_back();
        sink_down(0);
    }
    return max_value;
}
