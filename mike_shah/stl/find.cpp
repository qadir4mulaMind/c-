#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 5, 3, 7, 0};

    auto result = std::find(v.begin(), v.end(), 7);

    if (result != v.end()) {
        std::cout << *result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
