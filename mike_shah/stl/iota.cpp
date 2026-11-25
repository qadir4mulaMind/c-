#include <iostream>
#include <vector>
#include <numeric> 

int main() {
    std::vector<int> v(10);

    std::iota(v.begin(), v.end(), 0);

    std::cout << "Vector filled from 0: ";
    for (int ele : v) {
        std::cout << ele << " ";
    }
    std::cout << std::endl; // Output: 0 1 2 3 4 5 6 7 8 9

    // 2. Aap kisi bhi number se shuruat kar sakte hain (e.g., 100 se)
    std::vector<int> v2(5);
    std::iota(v2.begin(), v2.end(), 100);

    std::cout << "Vector filled from 100: ";
    for (int ele : v2) {
        std::cout << ele << " ";
    }
    std::cout << std::endl; // Output: 100 101 102 103 104

    // 3. Yeh char/characters par bhi kaam karta hai!
    std::vector<char> alphabet(5);
    std::iota(alphabet.begin(), alphabet.end(), 'A');

    std::cout << "Alphabets: ";
    for (char c : alphabet) {
        std::cout << c << " ";
    }
    std::cout << std::endl; // Output: A B C D E

    return 0;
}

