#include <iostream>
#include <list>

void print_list(const std::list<int>& l) {
    for (int val : l) std::cout << val << " ";
    std::cout << "\n";
}

int main() {
    std::list<int> numbers = {1, 4, 7, 10, 13, 16, 20, 25};
    std::cout << "Original list: ";
    print_list(numbers);

    // 1. Remove all ODD numbers using a lambda expression
    numbers.remove_if([](int n) { 
        return n % 2 != 0; 
    });
    std::cout << "After removing odd numbers: ";
    print_list(numbers); // Output: 4 10 16 20

    // 2. Remove numbers greater than 12
    numbers.remove_if([](int n) { 
        return n > 12; 
    });
    std::cout << "After removing elements > 12: ";
    print_list(numbers); // Output: 4 10
                         
    for(std::list<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it){
      std::cout << "reverse : " << *it << std::endl;
    }

    std::list<int> lst2{2, 3, 4, 5, 6};

    numbers.merge(lst2);

    std::cout << std::endl;

    for(auto x : numbers){
      std::cout << x << std::endl;
    }

    std::cout << std::endl;

    for(auto x : lst2){
      std::cout << x << std::endl;
    }

    std::list<int> lst1{0, 9, 8, 7, 6};

    lst1.splice(end(lst1), numbers);

    std::cout << std::endl;

    for(auto x : lst1){
      std::cout << x << std::endl;
    }
    return 0;
}

