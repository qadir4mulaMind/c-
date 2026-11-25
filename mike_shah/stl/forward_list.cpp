#include <iostream>
#include <forward_list>
#include <vector>
#include <string_view>

// Helper function to print elements using cbegin() and cend()
void print_flist(std::string_view label, const std::forward_list<int>& fl) {
    std::cout << label << ": [ ";
    for (auto it = fl.cbegin(); it != fl.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "=== 1. CONSTRUCTORS, ASSIGNMENT & CAPACITY ===\n";
    // Default and Initializer list constructors
    std::forward_list<int> fl1 = {10, 20, 30};
    print_flist("Initial fl1", fl1);

    // operator= assignment
    std::forward_list<int> fl2;
    fl2 = fl1;
    
    // assign() member function
    fl2.assign({5, 6, 7});
    print_flist("After assign() fl2", fl2);

    // C++23 assign_range()
    std::vector<int> vec = {100, 200};
    fl2.assign_range(vec);
    print_flist("After assign_range() fl2", fl2);

    // Capacity checking (Note: forward_list has no size() member function!)
    std::cout << "Is fl1 empty? " << (fl1.empty() ? "Yes" : "No") << "\n";
    std::cout << "Max size possible: " << fl1.max_size() << "\n\n";

    std::cout << "=== 2. ELEMENT ACCESS & ITERATORS ===\n";
    // front() element access
    std::cout << "First element of fl1: " << fl1.front() << "\n";

    // before_begin() / cbefore_begin() represents the slot BEFORE index 0
    auto before_it = fl1.cbefore_begin(); 
    
    std::cout << "=== 3. MODIFIERS (Push, Prepend, Insert, Erase) ===\n";
    // push_front() and emplace_front()
    fl1.push_front(5);
    fl1.emplace_front(1);
    
    // C++23 prepend_range()
    std::vector<int> prefix = {11, 12};
    fl1.prepend_range(prefix);
    print_flist("After front modifications fl1", fl1); // [ 11 12 1 5 10 20 30 ]

    // pop_front()
    fl1.pop_front();
    print_flist("After pop_front() fl1", fl1); // [ 12 1 5 10 20 30 ]

    // insert_after() and emplace_after() 
    auto it = fl1.begin(); // Points to 12
    fl1.insert_after(it, 99); // Inserts 99 AFTER 12
    fl1.emplace_after(it, 88); // Inserts 88 AFTER 12 (shifts 99 right)
    print_flist("After insertions after head", fl1); // [ 12 88 99 1 5 10 20 30 ]

    // C++23 insert_range_after()
    it = fl1.begin(); // Reset to head (12)
    fl1.insert_range_after(it, std::vector<int>{2, 3});
    print_flist("After insert_range_after()", fl1); // [ 12 2 3 88 99 1 5 10 20 30 ]

    // erase_after()
    it = fl1.begin(); // Points to 12
    fl1.erase_after(it); // Erases the element AFTER 12 (which is 2)
    print_flist("After erase_after()", fl1); // [ 12 3 88 99 1 5 10 20 30 ]

    // resize() and swap()
    std::forward_list<int> swapper = {55, 66};
    fl1.swap(swapper);
    print_flist("fl1 after swap()", fl1); // [ 55 66 ]
    print_flist("swapper after swap()", swapper);
    
    swapper.resize(4, 0); // Resize to 4 elements, fill new spaces with 0
    print_flist("swapper after resize(4, 0)", swapper); // [ 12 3 88 99 0 0... ]
    std::cout << "\n";

    std::cout << "=== 4. OPERATIONS (Algorithms) ===\n";
    std::forward_list<int> op_list = {40, 10, 30, 20, 30, 50};
    print_flist("Original op_list", op_list);

    // sort()
    op_list.sort();
    print_flist("After sort()", op_list); // [ 10 20 30 30 40 50 ]

    // unique() - removes consecutive duplicates
    op_list.unique();
    print_flist("After unique()", op_list); // [ 10 20 30 40 50 ]

    // reverse()
    op_list.reverse();
    print_flist("After reverse()", op_list); // [ 50 40 30 20 10 ]

    // remove() and remove_if()
    op_list.remove(40); // Removes all elements equal to 40
    op_list.remove_if([](int n) { return n % 2 != 0; }); // Removes odd numbers (50, 30, 10 remain)
    print_flist("After remove(40) & remove_if(odd)", op_list); // [ 50 30 20 ]

    // splice_after() - transfers nodes without memory reallocations
    std::forward_list<int> other_list = {700, 800};
    auto op_it = op_list.begin(); // Points to 50
    op_list.splice_after(op_it, other_list); // Moves elements from other_list AFTER 50
    print_flist("op_list after splice_after()", op_list); // [ 50 700 800 30 20 ]
    print_flist("other_list (should be empty)", other_list);

    // merge() - merges two sorted lists into one sorted list
    std::forward_list<int> list_a = {10, 30, 50};
    std::forward_list<int> list_b = {20, 40, 60};
    list_a.merge(list_b);
    print_flist("After merge() list_a", list_a); // [ 10 20 30 40 50 60 ]
    std::cout << "\n";

    std::cout << "=== 5. NON-MEMBER OPERATIONS & C++20 ERASURE ===\n";
    // Lexicographical comparison operator<=> (C++20)
    std::forward_list<int> comp1 = {1, 2, 3};
    std::forward_list<int> comp2 = {1, 2, 4};
    std::cout << "Is comp1 == comp2? " << ((comp1 == comp2) ? "True" : "False") << "\n";
    std::cout << "Is comp1 < comp2? " << ((comp1 < comp2) ? "True" : "False") << "\n";

    // Non-member std::erase and std::erase_if (C++20 Uniform Container Erasure)
    std::forward_list<int> erase_list = {1, 2, 3, 2, 4, 2};
    std::erase(erase_list, 2); // Deletes all 2s globally
    print_flist("After non-member std::erase()", erase_list); // [ 1 3 4 ]

    // clear()
    erase_list.clear();
    std::cout << "Is erase_list empty after clear()? " << (erase_list.empty() ? "Yes" : "No") << "\n";

    return 0;
}

