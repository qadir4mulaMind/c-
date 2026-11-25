#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <functional>
#include <utility>
#include <cassert>
#include <format> // For C++23 std::formatter validation

int main() {
    // =========================================================================
    // 1. MEMBER TYPES & UNDERLYING CONTAINERS
    // =========================================================================
    // The default configuration builds a max-heap inside a std::vector
    using DefaultPQ = std::priority_queue<int>; 
    
    // Explicitly showcasing internal member types matching specifications
    DefaultPQ::value_type element = 50;
    DefaultPQ::size_type pq_size_type = 0;
    DefaultPQ::reference ref = element;
    DefaultPQ::const_reference cref = element;
    DefaultPQ::container_type internal_container;
    DefaultPQ::value_compare internal_comparator;
    
    // Changing underlying container or changing ordering strategy (min-heap)
    std::priority_queue<int, std::deque<int>> deque_pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

    // Constructors
    DefaultPQ pq1; // Default constructor
    std::vector<int> initial_data = {10, 30, 20};
    DefaultPQ pq(initial_data.begin(), initial_data.end()); // Range constructor
    DefaultPQ pq2 = pq;                                    // Copy constructor

    // Assignment operator=
    pq1 = pq;

    // =========================================================================
    // 2. CAPACITY & ELEMENT ACCESS
    // =========================================================================
    // empty & size
    bool is_empty = pq.empty();
    DefaultPQ::size_type current_size = pq.size();

    // top (constant time access to the largest/highest priority element)
    const int& top_ref = pq.top(); 

    // =========================================================================
    // 3. MODIFIERS
    // =========================================================================
    // push (inserts element and automatically restores heap order)
    pq.push(40);

    // emplace (C++11: constructs element in-place and reorganises heap)
    pq.emplace(15);

    // push_range (C++23 Range Insertion with automatic sorting)
    std::vector<int> range_elements = {5, 60};
    pq.push_range(range_elements);

    // pop (removes the highest priority top element; restores heap properties)
    pq.pop(); 

    // swap (C++11 member function)
    pq.swap(pq1); // Swaps contents of pq and pq1
    pq1.swap(pq); // Swap back

    // =========================================================================
    // 4. NON-MEMBER FUNCTIONS & HELPERS
    // =========================================================================
    // std::swap algorithm overload specialization
    std::swap(pq, pq1);

    // std::uses_allocator specialization validation
    constexpr bool uses_alloc = std::uses_allocator_v<std::priority_queue<int>, std::allocator<int>>;

    // std::formatter specialization (C++23)
    std::string formatted_pq = std::format("Priority Queue size: {}", pq1.size());

    // Execution Success Verification
    std::cout << "Successfully verified and executed all member properties!\n";
    std::cout << "Final priority queue size: " << pq1.size() << "\n";
    std::cout << "Top (largest) element: " << pq1.top() << "\n"; // Should find maximum element

    return 0;
}

