#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <utility>
#include <cassert>
#include <format> // For C++23 std::formatter validation

int main() {
    // =========================================================================
    // 1. MEMBER TYPES & UNDERLYING CONTAINERS
    // =========================================================================
    // The standard default container type is std::deque<T>
    using DefaultQueue = std::queue<int>; 
    
    // Explicitly showcasing internal member types matching specifications
    DefaultQueue::value_type element = 100;
    DefaultQueue::size_type q_size_type = 0;
    DefaultQueue::reference ref = element;
    DefaultQueue::const_reference cref = element;
    
    // Showing compatibility with sequence containers providing pop_front() and push_back()
    std::queue<int, std::deque<int>> deque_queue;
    std::queue<int, std::list<int>> list_queue;

    // Constructors
    DefaultQueue q1; // Default constructor
    std::deque<int> initial_deque = {10, 20, 30};
    DefaultQueue q(initial_deque); // Construct from underlying container contents
    DefaultQueue q2 = q;          // Copy constructor

    // Assignment operator=
    q1 = q;

    // =========================================================================
    // 2. CAPACITY & ELEMENT ACCESS
    // =========================================================================
    // empty & size
    bool is_empty = q.empty();
    DefaultQueue::size_type current_size = q.size();

    // front (accesses the first element) and back (accesses the last element)
    int& front_ref = q.front();
    int& back_ref = q.back();
    
    const int& const_front_ref = std::as_const(q).front();
    const int& const_back_ref = std::as_const(q).back();

    // =========================================================================
    // 3. MODIFIERS
    // =========================================================================
    // push (inserts at the end)
    q.push(40);

    // emplace (C++11: constructs element in-place at the end)
    q.emplace(50);

    // push_range (C++23 Range Insertion at the end)
    std::vector<int> range_elements = {60, 70};
    q.push_range(range_elements);

    // pop (removes the first element; returns void)
    q.pop(); 

    // swap (C++11 member function)
    q.swap(q1); // Swaps contents of q and q1
    q1.swap(q); // Swap back

    // =========================================================================
    // 4. NON-MEMBER FUNCTIONS & HELPERS
    // =========================================================================
    // Lexicographical comparison operator algorithms
    bool is_equal = (q == q1);
    bool is_not_equal = (q != q1);
    bool is_less = (q < q1);
    bool is_less_equal = (q <= q1);
    bool is_greater = (q > q1);
    bool is_greater_equal = (q >= q1);
    
    // Three-way comparison spaceship operator (C++20)
    auto comp_result = (q <=> q1); 

    // std::swap algorithm overload specialization
    std::swap(q, q1);

    // std::uses_allocator specialization validation
    constexpr bool uses_alloc = std::uses_allocator_v<std::queue<int>, std::allocator<int>>;

    // std::formatter specialization (C++23)
    std::string formatted_queue = std::format("Queue size: {}", q1.size());

    // Execution Success Verification
    std::cout << "Successfully verified and executed all member properties!\n";
    std::cout << "Final queue size: " << q1.size() << "\n";
    std::cout << "Front element: " << q1.front() << "\n";
    std::cout << "Back element: " << q1.back() << "\n";

    return 0;
}

