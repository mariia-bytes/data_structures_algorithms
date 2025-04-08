#include <iostream>

void bubble_sort(int array[], int size);

// helper template function to print arrays
template <size_t N>
void print_array(const int (&array)[N]) {
    std::cout << "[ ";
    for (auto i : array) {
        std::cout << i << " ";
    }
    std::cout << "]\n";
}

// helper function to copy the array
void copy_array(const int source_array[], int destination_array[], const int size) {
    for (int i; i < size; i++) {
        destination_array[i] = source_array[i];
    }
}

int main() {

    int array[] = {6, 4, 5, 2, 3, 1};

    std::cout << "\nInitial array: ";
    print_array(array);
    
    // calculate the size of the array
    int size = sizeof(array)/sizeof(array[0]); // sizeof() returns the bytes

    // bubble sort
    int bubble_sorted[size];
    copy_array(array, bubble_sorted, size);
    
    bubble_sort(array, size);

    std::cout << "\nAfter bubble sort: ";
    print_array(array);
    
    


    return 0;
}


void bubble_sort(int array[], int size) {
    for (unsigned int i = size - 1; i > 0; i--) {
        for (unsigned int j {0}; j < i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}