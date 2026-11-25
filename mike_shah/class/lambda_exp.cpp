#include <iostream>
#include <functional>
template<typename Op, typename First, typename... Args>
auto DoEverything(Op op, First first, Args... args) {
    ((first = op(first, args)), ...);
    return first;
}

int main() {
    auto sum = DoEverything(std::plus<>(), 1, 2, 3, 4);
    std::cout << " (Sum): " << sum << std::endl; 
    auto prod = DoEverything(std::multiplies<>(), 1, 2, 3, 4);
    std::cout << " (Product): " << prod << std::endl; 

    return 0;
}

