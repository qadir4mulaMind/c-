#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> // Required for std::for_each

int main() {
    // Fixed type alias and vector initialization
    std::vector<int> c(5); 

    // C-style loop (Fixed missing quotes around string literal)
    std::cout << "C-Style Loop" << std::endl;
    for (size_t i = 0; i < c.size(); ++i) { // Using c.size() is safer than capacity()
        std::cout << c[i] << std::endl;
    }

    // C++98 style loop iterators (Fixed missing quotes)
    std::cout << "C++ 98 - Style Iterator Loop" << std::endl;
    for (auto it = c.begin(); it != c.end(); it++) {
        std::cout << *it << std::endl;
    }

    // std::algorithm Loop (Fixed missing quotes and missing << operator)
    std::cout << "std::algorithm Loop" << std::endl;
    std::for_each(c.begin(), c.end(), [](const auto &e) {
        std::cout << e << std::endl; 
    });

    // Range-based loop (Fixed missing quotes)
    std::cout << "Range based loop" << std::endl;
    for (const auto& e : c) {
        std::cout << e << std::endl;
    }

    return 0;
}

