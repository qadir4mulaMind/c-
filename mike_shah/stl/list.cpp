#include <iostream>
#include <list>
#include <algorithm>

// Helper function to print any list
void print_list(std::string_view label, const std::list<int>& l) {
    std::cout << label << ": [ ";
    for (int val : l) {
        std::cout << val << " ";
    }
    std::cout << "]\n";
}

int main() {
    // =========================================================================
    // 1. INITIALIZATION & CAPACITY
    // =========================================================================
    std::list<int> list1 = {10, 20, 30, 40};
    
    std::cout << "Is empty: " << (list1.empty() ? "Yes" : "No") << "\n";
    std::cout << "Size: " << list1.size() << "\n";

    // =========================================================================
    // 2. ELEMENT ACCESS & ITERATORS
    // =========================================================================
    std::cout << "First element: " << list1.front() << "\n";
    std::cout << "Last element: " << list1.back() << "\n";

    // Using reverse iterators to print backward
    std::cout << "Backward: [ ";
    for (auto it = list1.rbegin(); it != list1.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]\n\n";

    // =========================================================================
    // 3. MODIFIERS (Add, Insert, Remove, Clear)
    // =========================================================================
    // Adding elements
    list1.push_front(5);       // Add to start
    list1.push_back(50);       // Add to end
    list1.emplace_back(60);    // Construct in-place at end
    print_list("After additions", list1); // [ 5 10 20 30 40 50 60 ]

    // Inserting in the middle
    auto it = list1.begin();
    std::advance(it, 2);       // Move iterator to 3rd position (value 20)
    list1.insert(it, 15);      // Insert 15 before 20
    print_list("After insert", list1); // [ 5 10 15 20 30 40 50 60 ]

    // Removing from ends
    list1.pop_front();
    list1.pop_back();
    print_list("After popping ends", list1); // [ 10 15 20 30 40 50 ]

    // Erasing from middle
    it = list1.begin();
    std::advance(it, 1);       // Points to 15
    list1.erase(it);           // Erase 15
    print_list("After erase", list1); // [ 10 20 30 40 50 ]
    std::cout << "\n";

    // =========================================================================
    // 4. LIST-SPECIFIC OPERATIONS (The unique pointer-manipulation methods)
    // =========================================================================
    std::list<int> list2 = {35, 15, 25, 25, 45};
    print_list("List 2 (Original)", list2);

    // Sort (Required because std::sort doesn't work on lists)
    list2.sort();
    print_list("After sort()", list2); // [ 15 25 25 35 45 ]

    // Unique (Removes consecutive duplicates)
    list2.unique();
    print_list("After unique()", list2); // [ 15 25 35 45 ]

    // Reverse
    list2.reverse();
    print_list("After reverse()", list2); // [ 45 35 25 15 ]

    // Remove matching elements
    list2.remove(35); // Removes all elements equal to 35
    print_list("After remove(35)", list2); // [ 45 25 15 ]

    // Remove conditionally (Remove if odd using a C++ lambda expression)
    list2.remove_if([](int n) { return n % 2 != 0; });
    print_list("After remove_if(odd)", list2); // [ 25 ] (15 and 45 were removed)
    std::cout << "\n";

    // =========================================================================
    // 5. SPLICE & MERGE
    // =========================================================================
    std::list<int> source = {100, 200, 300};
    std::list<int> dest = {1, 2, 3};

    // Splice: Move elements from source into dest without copying memory
    auto dest_it = dest.begin();
    std::advance(dest_it, 1); // Points to 2
    
    dest.splice(dest_it, source); // Inserts ALL of source right before 2
    print_list("Dest after splice", dest); // [ 1 100 200 300 2 3 ]
    print_list("Source after splice", source); // [ ] (Now empty!)

    // Merge: Combines two sorted lists into one sorted list
    std::list<int> m1 = {10, 30, 50};
    std::list<int> m2 = {20, 40, 60};
    m1.merge(m2); 
    print_list("After merge", m1); // [ 10 20 30 40 50 60 ]
    
    // Clear everything
    m1.clear();
    std::cout << "m1 size after clear(): " << m1.size() << "\n";

    return 0;
}

