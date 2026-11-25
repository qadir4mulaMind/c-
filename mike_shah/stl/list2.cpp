#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {10, 20, 30, 40};

    // Explicitly using cbegin() and cend() for a read-only loop
    for (auto it = myList.cbegin(); it != myList.cend(); ++it) {
        std::cout << *it << " ";
        
    }
    std::cout << "\n";

    return 0;
}

