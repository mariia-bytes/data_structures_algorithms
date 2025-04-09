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

void merge(std::vector<int>& vec, size_t start, size_t middle, size_t end);
void merge_sort(std::vector<int>& vec, size_t left, size_t right);

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
void merge_sort(std::vector<int>& vec, size_t left, size_t right) {
    std::cout << "Merge Sort for left = " << left << ", right = " << right << std::endl;
    
    // merge until we are left with a single element
    if (left < right) {
        // calculate mid point of a vector
        size_t mid = (left + right)/2;

        // sort the sub-vectors
        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);

        // merge the two sub-vectors
        merge(vec, left, mid, right);
    }
}

// merges two sorted subvectors into one
void merge(std::vector<int>& vec, size_t start, size_t middle, size_t end, int depth) {
    // std::cout << "Call Merge for start = " << start << ", end = " << end << std::endl;
    std::string indent(depth * 2, ' ');
    std::cout << indent << "🔁 MERGING: [" << start << " - " << end << "]\n";

    /// NOT sorting in-place. Uses two temp vectors

    // init left-hand elements
    size_t elements_left = middle - start + 1;
    std::vector<int> temp_left;
    for (size_t i {0}; i < elements_left; i++) {
        temp_left.push_back(vec[start + i]);
    }

    // init right-hand elements
    size_t elements_right = end - middle;
    std::vector<int> temp_right;
    for (size_t i {0}; i < elements_right; i++) {
        temp_right.push_back(vec[middle + 1 + i]);
    }

    print_sub_vectors(temp_left, temp_right);

    // compare vectors and add elements to the final result
    size_t i {0};
    size_t j {0};
    size_t pos = start;

    while ((i < temp_left.size()) && (j < temp_right.size())) {
        // add left-hand element is it's smaller
        // otherwise add right-hand element
        if (temp_left[i] <= temp_right[j]) {
            vec[pos] = temp_left[i];
            i++;
        } else {
            vec[pos] = temp_right[j];
            j++;
        }
        // increment position in final vector
        pos++;
    }

    // clean up remainig left-hand elements
    while (i < temp_left.size()) {
        vec[pos] = temp_left[i];
        i++;
        pos++;
    }

    // clean up remainig right-hand elements
    while (i < temp_right.size()) {
        vec[pos] = temp_right[j];
        j++;
        pos++;
    }

    print_range(vec, start, end);

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

    merge_sort(vec, 0, vec.size() - 1);

    std::cout << "\nSorted vector:\n";
    print_vector(vec);

    return 0;
}