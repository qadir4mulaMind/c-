#include <iostream>
#include <list>
#include <iterator> // Required for std::advance

int main() {
    std::list<int> myList = {10, 20, 30, 40, 50};

    // 1. Move Forward
    auto it = myList.begin();
    std::advance(it, 3); // Moves it 3 steps forward (points to 40)
    std::cout << "Advanced 3 steps: " << *it << "\n";

    // 2. Move Backward
    std::advance(it, -2); // Moves it 2 steps backward (points to 20)
    std::cout << "Advanced -2 steps: " << *it << "\n";

    return 0;
}

