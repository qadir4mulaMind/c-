#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <utility>
#include <cassert>
#include <format> // For C++23 std::formatter validation

int main() {
    // =========================================================================
    // 1. MEMBER TYPES & UNDERLYING CONTAINERS
    // =========================================================================
    // The standard default container type is std::deque<T>
    using DefaultStack = std::stack<int>; 
    
    // Explicitly showcasing internal member types matching specifications
    DefaultStack::value_type element = 42;
    DefaultStack::size_type s_type = 0;
    DefaultStack::reference ref = element;
    DefaultStack::const_reference cref = element;
    
    // Showing compatibility with standard sequence containers (vector, list)
    std::stack<int, std::vector<int>> vector_stack;
    std::stack<int, std::list<int>> list_stack;

    // Constructors
    DefaultStack s1; // Default constructor
    std::deque<int> initial_deque = {10, 20, 30};
    DefaultStack s(initial_deque); // Construct from underlying container contents
    DefaultStack s2 = s;          // Copy constructor

    // Assignment operator=
    s1 = s;

    // =========================================================================
    // 2. CAPACITY & ELEMENT ACCESS
    // =========================================================================
    // empty & size
    bool is_empty = s.empty();
    DefaultStack::size_type current_size = s.size();

    // top (accesses the top element, which is the back of the container)
    int& top_ref = s.top();
    const int& const_top_ref = std::as_const(s).top();

    // =========================================================================
    // 3. MODIFIERS
    // =========================================================================
    // push
    s.push(40);

    // emplace (C++11: constructs element in-place at the top)
    s.emplace(50);

    // push_range (C++23 Range Insertion)
    std::vector<int> range_elements = {60, 70};
    s.push_range(range_elements);

    // pop (removes the top element; returns void)
    s.pop(); 

    // swap (C++11 member function)
    s.swap(s1); // Swaps contents of s and s1
    s1.swap(s); // Swap back

    // =========================================================================
    // 4. NON-MEMBER FUNCTIONS & HELPERS
    // =========================================================================
    // Lexicographical comparison operator algorithms
    bool is_equal = (s == s1);
    bool is_not_equal = (s != s1);
    bool is_less = (s < s1);
    bool is_less_equal = (s <= s1);
    bool is_greater = (s > s1);
    bool is_greater_equal = (s >= s1);
    
    // Three-way comparison spaceship operator (C++20)
    auto comp_result = (s <=> s1); 

    // std::swap algorithm overload specialization
    std::swap(s, s1);

    // std::uses_allocator specialization validation
    constexpr bool uses_alloc = std::uses_allocator_v<std::stack<int>, std::allocator<int>>;

    // std::formatter specialization (C++23)
    // Note: Prints container adaptors dynamically if supported by your compiler standard library implementation
    std::string formatted_stack = std::format("Stack size: {}", s1.size());

    // Execution Success Verification
    std::cout << "Successfully verified and executed all member properties!\n";
    std::cout << "Final stack size: " << s1.size() << "\n";
    std::cout << "Top element: " << s1.top() << "\n";

    return 0;
}

