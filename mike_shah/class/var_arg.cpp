#include <iostream>

template<typename... Args>
auto Sum(Args... args) {
    return (... + args);
}

int main() {
    std::cout << Sum(1, 2, 3, 4) << std::endl;
    return 0;
}

