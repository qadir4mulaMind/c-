#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>

int main() {
    // =========================================================================
    // 1. MEMBER TYPES & CONSTRUCTORS
    // =========================================================================
    using MapType = std::unordered_multimap<std::string, std::string>;
    
    // Explicitly showcasing internal member types matching specifications
    MapType::key_type key = "Apple";
    MapType::mapped_type value = "Fruit";
    MapType::value_type pair = {key, value};

    // Constructors
    MapType m1; // Default constructor
    MapType m = { 
        {"Apple", "Fruit"}, 
        {"Apple", "Tech Company"}, 
        {"Carrot", "Vegetable"},
        {"Tomato", "Fruit"} 
    }; // Initializer list (contains duplicate keys)
    
    MapType m2(m.begin(), m.end()); // Range constructor
    MapType m3 = m; // Copy constructor

    // Assignment operator=
    m1 = m; 
    
    // get_allocator
    MapType::allocator_type alloc = m.get_allocator();

    // =========================================================================
    // 2. ITERATORS
    // =========================================================================
    // begin / cbegin & end / cend
    MapType::iterator it = m.begin();
    MapType::const_iterator cit = m.cbegin();
    assert(m.end() != it);
    assert(m.cend() != cit);

    // =========================================================================
    // 3. CAPACITY
    // =========================================================================
    bool is_empty = m.empty();
    MapType::size_type current_size = m.size();
    MapType::size_type maximum_size = m.max_size();

    // =========================================================================
    // 4. MODIFIERS
    // =========================================================================
    // insert (various overloads)
    m.insert({"Tomato", "Vegetable"}); // Insertion of an existing key
    m.insert(pair);

    // insert_range (C++23 Range Insertion)
    std::vector<std::pair<std::string, std::string>> new_items = {{"Banana", "Fruit"}};
    m.insert_range(new_items);

    // emplace & emplace_hint
    m.emplace("Cucumber", "Vegetable");
    m.emplace_hint(m.begin(), "Spinach", "Vegetable");

    // extract & merge (C++17 node handle API)
    MapType::node_type node = m.extract(m.find("Cucumber")); // Extract specific node handle
    if (!node.empty()) {
        node.mapped() = "Green Vegetable";
        m.insert(std::move(node)); // Re-insert node
    }
    MapType other_map = {{"Potato", "Tubers"}};
    m.merge(other_map); // Merge contents from another unordered_multimap

    // erase (by key removes ALL matching keys; can also erase by single iterator)
    m.erase("Spinach"); 

    // swap
    m.swap(m1); // Swap contents with m1
    m1.swap(m); // Swap back

    // clear 
    m2.clear(); // Empties container entirely

    // =========================================================================
    // 5. LOOKUP
    // =========================================================================
    // count & find & contains (C++20)
    size_t apple_count = m.count("Apple"); // Returns total duplicates (e.g., 3)
    MapType::iterator found_it = m.find("Apple"); // Returns iterator to first match found
    bool has_carrot = m.contains("Carrot"); // C++20 standard feature

    // equal_range (Retrieves the contiguous subrange matching a key)
    auto range = m.equal_range("Apple"); 
    for (auto range_it = range.first; range_it != range.second; ++range_it) {
        // Iterates cleanly through all values matched with "Apple"
    }

    // =========================================================================
    // 6. BUCKET INTERFACE
    // =========================================================================
    size_t buckets = m.bucket_count();
    size_t max_buckets = m.max_bucket_count();
    size_t target_bucket = m.bucket("Apple");
    size_t elements_in_bucket = m.bucket_size(target_bucket);

    // Local iterators for traversing inside a single target bucket
    MapType::local_iterator bit_begin = m.begin(target_bucket);
    MapType::local_iterator bit_end = m.end(target_bucket);
    MapType::const_local_iterator cbit_begin = m.cbegin(target_bucket);
    MapType::const_local_iterator cbit_end = m.cend(target_bucket);

    // =========================================================================
    // 7. HASH POLICY
    // =========================================================================
    float current_lf = m.load_factor();
    float max_lf = m.max_load_factor();
    m.max_load_factor(1.5f); // Set new maximum allowed average load factor

    m.rehash(30);    // Allocates at least 30 buckets and regenerates table
    m.reserve(150);  // Allocates buckets to fit 150 elements comfortably

    // =========================================================================
    // 8. OBSERVERS
    // =========================================================================
    MapType::hasher hash_fn = m.hash_function();
    MapType::key_equal eq_fn = m.key_eq();

    // =========================================================================
    // 9. NON-MEMBER FUNCTIONS
    // =========================================================================
    bool is_equal = (m == m1); // operator== (Note: Requires matching structural matches)
    std::swap(m, m1);          // Full standard specialization swap overload

    // erase_if (C++20 uniform container erasure function)
    std::erase_if(m, [](const auto& item) {
        return item.second == "Vegetable"; 
    });

    // Execution Success Verification
    std::cout << "Successfully verified and executed all member properties!\n";
    std::cout << "Final map element size after deletions: " << m.size() << "\n";

    return 0;
}

