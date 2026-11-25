#include <iostream>


inline int square(int num) {
    return num * num;
}

int main() {
    int x = 5;
    
    // Background mein compiler is line ko badal kar aisa kar dega: int result = 5 * 5;
    int result = square(x); 
    
    std::cout << "The square of " << x << " is: " << result << std::endl;
    
    return 0;
}
