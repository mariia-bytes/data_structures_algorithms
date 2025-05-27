#include <iostream>

// helper function to print arrays
void print_array(const int* array, size_t size) {
    std::cout << "[ ";
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

// helper function to swap values of the two given indexes
void swap(int array[], int first_index, int second_index) {
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

// helper function for the quick sort
int pivot(int array[], int pivot_index, int end_index) {
    int swap_index = pivot_index;
    for (int i = pivot_index + 1; i <= end_index; i++) {
        if (array[i] < array[pivot_index]) {
            swap_index++;
            swap(array, swap_index, i);
        }
    }
    swap(array, swap_index, pivot_index);

    return swap_index;
}

// recursive function for quick sort
void quick_sort(int array[], int left_index, int right_index) {
    // base case
    if (left_index >= right_index) return;

    int pivot_index = pivot(array, left_index, right_index);

    quick_sort(array, left_index, pivot_index - 1);
    quick_sort(array, pivot_index + 1, right_index);

}

int main() {
    int array[] = {4, 6, 1, 7, 3, 2, 5};
    int size = sizeof(array)/sizeof(array[0]);

    std::cout << "\nInitial array: ";
    print_array(array, size);

    int returned_index = pivot(array, 0, size - 1);

    std::cout << "\nPivot index: " << returned_index << "\n";
    std::cout << "Array after pivot: ";
    print_array(array, size);

    quick_sort(array, 0, size - 1);
    std::cout << "Array after quick sort: ";
    print_array(array, size);

    return 0;
}