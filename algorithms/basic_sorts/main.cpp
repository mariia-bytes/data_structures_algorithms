#include <iostream>

// sort functions prototypes
void bubble_sort(int array[], const size_t size);
void selection_sort(int array[], const size_t size);
void insertion_sort(int array[], const size_t size);

// helper template function for printing the initial array
// (note: it was supposed to work with all arrays but the compiler is cunning)
template <size_t N>
void print_array(const int (&array)[N]) {
    std::cout << "[ ";
    for (auto i : array) {
        std::cout << i << " ";
    }
    std::cout << "]\n";
}

// helper function for printing copied arrays
void print_array(const int* array, size_t size) {
    std::cout << "[ ";
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

// helper function to copy the array
void copy_array(const int source_array[], int destination_array[], const size_t size) {
    for (size_t i {0}; i < size; i++) {
        destination_array[i] = source_array[i];
    }
}

int main() {

    int array[] = {6, 4, 5, 2, 3, 1};

    std::cout << "\nInitial array: ";
    print_array(array);
    
    // calculate the size of the array
    size_t size = sizeof(array)/sizeof(array[0]); // sizeof() returns the bytes


    /***** bubble sort ******************************/ 
    int bubble_sorted[size];
    copy_array(array, bubble_sorted, size);
    
    bubble_sort(bubble_sorted, size);

    std::cout << "\nAfter BUBBLE sort: ";
    print_array(bubble_sorted, size);


    /***** selection sort ******************************/
    int selection_sorted[size];
    copy_array(array, selection_sorted, size);

    selection_sort(selection_sorted, size);

    std::cout << "\nAfter SELECTION sort: ";
    print_array(selection_sorted, size);


    /***** insertion sort ******************************/
    int insertion_sorted[size];
    copy_array(array, insertion_sorted, size);

    insertion_sort(insertion_sorted, size);

    std::cout << "\nAfter INSERTION sort: ";
    print_array(insertion_sorted, size);


    return 0;
}



// BUBBLE SORT
void bubble_sort(int array[], const size_t size) {
    if (size == 0) return; // guard case for the following for-loop
    for (size_t i = size - 1; i > 0; i--) {
        for (size_t j {0}; j < i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// SELECTION SORT
void selection_sort(int array[], const size_t size) {
    for (size_t i {0}; i < size; i++) {
        size_t min_index = i;
        for (size_t j {i+1}; j < size; j++) {
            if (array[min_index] > array[j]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

// INSERTION sort
void insertion_sort(int array[], const size_t size) {
    for (size_t i {1}; i < size; i++) {
        int temp = array[i];
        int j = static_cast<int>(i) - 1;      
        while (j > -1 && temp < array[j]) {
            array[j+1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}