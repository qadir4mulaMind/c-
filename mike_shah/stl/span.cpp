#include <iostream>
#include <span>
#include <vector>
#include <array>

// Function accepts a span. It works with any contiguous memory container.
void print_elements(std::span<const int> data) {
    std::cout << "Elements (Size: " << data.size() << "): ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. Works with C-style arrays
    int arr[] = {1, 2, 3};
    print_elements(arr);

    // 2. Works with std::vector
    std::vector<int> vec = {4, 5, 6, 7};
    print_elements(vec);

    // 3. Works with std::array
    std::array<int, 2> std_arr = {8, 9};
    print_elements(std_arr);

    // 4. Creating a subview (e.g., skipping the first element, take next 2)
    std::span<int> full_span{vec};
    std::span<int> middle_part = full_span.subspan(1, 2); // view of {5, 6}
    print_elements(middle_part);
}

