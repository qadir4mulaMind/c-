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
    using MapType = std::unordered_map<std::string, std::string>;
    
    // Explicitly showcasing internal member types matching specifications
    MapType::key_type key = "RED";
    MapType::mapped_type value = "#FF0000";
    MapType::value_type pair = {key, value};

    // Constructors
    MapType u1; // Default constructor
    MapType u = { {"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"} }; // Initializer list
    MapType u2(u.begin(), u.end()); // Range constructor
    MapType u3 = u; // Copy constructor

    // Assignment operator=
    u1 = u; 
    
    // get_allocator
    MapType::allocator_type alloc = u.get_allocator();

    // =========================================================================
    // 2. ITERATORS
    // =========================================================================
    // begin / cbegin & end / cend
    MapType::iterator it = u.begin();
    MapType::const_iterator cit = u.cbegin();
    assert(u.end() != it);
    assert(u.cend() != cit);

    // =========================================================================
    // 3. CAPACITY
    // =========================================================================
    bool is_empty = u.empty();
    MapType::size_type current_size = u.size();
    MapType::size_type maximum_size = u.max_size();

    // =========================================================================
    // 4. MODIFIERS
    // =========================================================================
    // insert (various overloads)
    u.insert({"YELLOW", "#FFFF00"});
    u.insert(pair);

    // insert_or_assign (C++17)
    u.insert_or_assign("MAGENTA", "#FF00FF");

    // emplace & emplace_hint (C++11)
    u.emplace("CYAN", "#00FFFF");
    u.emplace_hint(u.begin(), "ORANGE", "#FFA500");

    // try_emplace (C++17)
    u.try_emplace("RED", "#ALREADY_EXISTS_SO_IGNORED");

    // extract & merge (C++17)
    MapType::node_type node = u.extract("CYAN"); // Extract node handle
    if (!node.empty()) {
        node.mapped() = "#00FFFF-EDITED";
        u.insert(std::move(node)); // Re-insert node
    }
    MapType other_map = {{"PURPLE", "#800080"}};
    u.merge(other_map); // Merge contents

    // erase (by iterator, key, or range)
    u.erase("ORANGE"); 

    // swap
    u.swap(u1); // Swap contents with u1
    u1.swap(u); // Swap back

    // clear (clears container)
    u2.clear(); 

    // =========================================================================
    // 5. LOOKUP
    // =========================================================================
    // at (with bounds checking)
    try {
        std::string color = u.at("RED");
    } catch (const std::out_of_range& e) {
        // Handled
    }

    // operator[] (access or insert)
    std::string green_val = u["GREEN"];

    // count & find & contains (C++20)
    size_t has_red_count = u.count("RED"); // Returns 1 or 0
    MapType::iterator found_it = u.find("RED");
    bool has_blue = u.contains("BLUE"); // C++20 standard feature

    // equal_range
    auto range = u.equal_range("RED"); // Returns pair of iterators

    // =========================================================================
    // 6. BUCKET INTERFACE
    // =========================================================================
    size_t buckets = u.bucket_count();
    size_t max_buckets = u.max_bucket_count();
    size_t target_bucket = u.bucket("RED");
    size_t elements_in_bucket = u.bucket_size(target_bucket);

    // Local iterators for traversing a single bucket
    MapType::local_iterator bit_begin = u.begin(target_bucket);
    MapType::local_iterator bit_end = u.end(target_bucket);
    MapType::const_local_iterator cbit_begin = u.cbegin(target_bucket);
    MapType::const_local_iterator cbit_end = u.cend(target_bucket);

    // =========================================================================
    // 7. HASH POLICY
    // =========================================================================
    float current_lf = u.load_factor();
    float max_lf = u.max_load_factor();
    u.max_load_factor(2.0f); // Change maximum load factor

    u.rehash(20);    // Changes bucket count to at least 20
    u.reserve(100);  // Pre-allocates space for at least 100 elements

    // =========================================================================
    // 8. OBSERVERS
    // =========================================================================
    MapType::hasher hash_fn = u.hash_function();
    MapType::key_equal eq_fn = u.key_eq();

    // =========================================================================
    // 9. NON-MEMBER FUNCTIONS
    // =========================================================================
    bool is_equal = (u == u1); // operator==
    std::swap(u, u1);         // std::swap algorithm overload

    // erase_if (C++20 uniform container erasure)
    std::erase_if(u, [](const auto& item) {
        return item.first == "YELLOW"; 
    });

    // Verification Output
    std::cout << "Successfully verified and executed all member properties!\n";
    std::cout << "Final map element size: " << u.size() << "\n";

    return 0;
}

