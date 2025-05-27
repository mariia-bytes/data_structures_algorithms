// This program implements merge sort in C++

#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()


// -------- Function Declarations -------- //
void init_vector(std::vector<int>& vec, size_t n);
void print_vector(const std::vector<int>& vec);
void print_range(const std::vector<int>& vec, const size_t& start, const size_t& end);
void print_sub_vectors(const std::vector<int>& vec1, const std::vector<int>& vec2);

void merge(std::vector<int>& vec, size_t start, size_t middle, size_t end, int depth);
void merge_sort(std::vector<int>& vec, size_t left, size_t right, int depth = 0);

// -------- Utility Functions -------- //

// initializes a vector with n random numbers
void init_vector(std::vector<int>& vec, size_t n) {
    for (size_t i {0}; i < n; i++) {
        vec.push_back(rand() % 100);
    }
}

// prints a full vector
void print_vector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (size_t i {0}; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";
}

// prints a subrange of a vector
void print_range(const std::vector<int>& vec, const size_t& start, const size_t& end) {
    std::cout << "[ ";
    for (size_t i = start; i < end + 1; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";
}

// prints two vectors side-by-side (for debugging)
void print_sub_vectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    for (size_t i {0}; i < vec1.size(); i++) {
        std::cout << vec1[i] << " ";
    }
    std::cout << "\t";
    for (size_t i {0}; i < vec2.size(); i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
}


// -------- Merge Sort Functions -------- //

// recursively sorts a subvector from left to right
void merge_sort(std::vector<int>& vec, size_t left, size_t right, int depth) {
    std::string indent(depth * 2, ' ');

    std::cout << indent << "🔍 merge_sort(left=" << left << ", right=" << right << ")\n";

    if (left < right) {
        size_t mid = (left + right) / 2;

        merge_sort(vec, left, mid, depth + 1);
        merge_sort(vec, mid + 1, right, depth + 1);

        merge(vec, left, mid, right, depth);
    }
}

// merges two sorted subvectors into one
void merge(std::vector<int>& vec, size_t start, size_t middle, size_t end, int depth) {
    // for a nice output
    std::string indent(depth * 2, ' ');

    std::cout << indent << "🔁 MERGING: [" << start << " - " << end << "]\n";

    // calculate the sizes of the left and right subvectors
    size_t left_size = middle - start + 1;
    size_t right_size = end - middle;

    // create two new vectors
    std::vector<int> temp_left(left_size);
    std::vector<int> temp_right(right_size);

    // populate the left vector
    for (size_t i = 0; i < left_size; i++) {
        temp_left[i] = vec[start + i];
    }

    // populate the right vector
    for (size_t i = 0; i < right_size; i++) {
        temp_right[i] = vec[middle + 1 + i];
    }

    std::cout << indent << "🧩 LEFT : ";
    print_vector(temp_left);

    std::cout << indent << "🧩 RIGHT: ";
    print_vector(temp_right);

    size_t i = 0; // for left vector
    size_t j = 0; // for right vector
    size_t pos = start; // for original vector

    // populate the original vector while one of the subvectors is not empty
    while (i < temp_left.size() && j < temp_right.size()) {
        if (temp_left[i] <= temp_right[j]) {
            vec[pos++] = temp_left[i++];
        } else {
            vec[pos++] = temp_right[j++];
        }
    }

    // if there are items left in left subvector
    while (i < temp_left.size()) {
        vec[pos++] = temp_left[i++];
    }

    // if there are items left in right subvector
    while (j < temp_right.size()) {
        vec[pos++] = temp_right[j++];
    }

    std::cout << indent << "✅ After merge: ";
    print_range(vec, start, end);
    std::cout << "\n";
}


// -------- Main Function -------- //

int main() {

    srand(time(0));  // seed random number generator

    std::vector<int> vec;
    size_t n = 8;
    init_vector(vec, n);

    std::cout << "\nOriginal vector:\n";
    print_vector(vec);
    std::cout << "\n";

    merge_sort(vec, 0, vec.size() - 1, 0);

    std::cout << "\nSorted vector:\n";
    print_vector(vec);

    return 0;
}