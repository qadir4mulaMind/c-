#include <iostream>
#include <algorithm> 
#include <vector>

int main() {
    int a = 10;
    int b = 20;

    // 1. Do numbers mein se min/max nikalna
    int minimum = std::min(a, b);
    int maximum = std::max(a, b);

    std::cout << "Min of 2 numbers: " << minimum << std::endl; // Output: 10
    std::cout << "Max of 2 numbers: " << maximum << std::endl; // Output: 20
    std::cout << "--------------------------------" << std::endl;

    // 2. Initializer List (Multiple numbers) mein se min/max nikalna
    int min_of_many = std::min({5, 3, 9, 1, 7});
    int max_of_many = std::max({5, 3, 9, 1, 7});

    std::cout << "Min of list: " << min_of_many << std::endl; // Output: 1
    std::cout << "Max of list: " << max_of_many << std::endl; // Output: 9
    std::cout << "--------------------------------" << std::endl;

    // 3. std::minmax ka use karke dono ek saath nikalna (C++11)
    // Yeh ek pair return karta hai: .first = min, .second = max
    auto result = std::minmax({45, 12, 89, 4, 67});
    std::cout << "Min-Max Pair -> Min: " << result.first << ", Max: " << result.second << std::endl;
    std::cout << "--------------------------------" << std::endl;

    // 4. Vector ke andar se min/max nikalna (std::min_element / std::max_element)
    std::vector<int> vec{15, 6, 88, -3, 42};
    
    // Yeh algorithms iterators return karte hain, isliye '*' (dereference) lagana hota hai
    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());

    std::cout << "Vector Min: " << *min_it << std::endl; // Output: -3
    std::cout << "Vector Max: " << *max_it << std::endl; // Output: 88

    return 0;
}

