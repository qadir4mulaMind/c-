#include <iostream>
#include <unordered_set> // Both unordered_set and unordered_multiset live here
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

// ============================================================================
// SYSTEM TYPE: CUSTOM CLASS & MULTI-HASHING ENGINE
// ============================================================================
struct LogEntry {
    int error_code;
    std::string message;

    // Defines how keys are evaluated for structural equality 
    bool operator==(const LogEntry& other) const {
        return error_code == other.error_code;
    }
};

// Functor mapping out how keys compute hash indexes
struct LogHasher {
    std::size_t operator()(const LogEntry& log) const {
        return std::hash<int>{}(log.error_code);
    }
};

// Console formatting block logging helper
void print_title(std::string_view title) {
    std::cout << "\n=========================================\n"
              << " " << title << "\n"
              << "=========================================\n";
}

int main() {
    // =========================================================================
    // 1. INITIALIZATION & MODIFIERS (Insertions & Emplace)
    // =========================================================================
    print_title("1. INITIALIZATION & ELEMENT MODIFIERS");

    // Intializer list constructor allows duplicate keys (e.g., three 40s)
    std::unordered_multiset<int> mset = {40, 10, 40, 20, 40, 30};
    
    std::cout << "Is container empty? " << (mset.empty() ? "Yes" : "No") << "\n";
    std::cout << "Total elements stored: " << mset.size() << "\n";
    std::cout << "System limit boundary capacity: " << mset.max_size() << "\n";

    // .insert() for multisets returns a direct iterator pointing to the item, NOT a pair
    auto insert_it = mset.insert(20); 
    std::cout << "Inserted duplicate element: " << *insert_it << "\n";

    // emplace() constructs element directly in place
    mset.emplace(50);

    // emplace_hint() provides an iterator placement optimization suggestion
    mset.emplace_hint(mset.begin(), 60);

    // C++23 insert_range() to stream variable components down into the payload
    std::vector<int> numbers_batch = {10, 70, 80};
    mset.insert_range(numbers_batch);

    std::cout << "All current collection elements: ";
    for (int x : mset) std::cout << x << " ";
    std::cout << "\n";

    // =========================================================================
    // 2. ADVANCED MULTI-LOOKUP METHODS
    // =========================================================================
    print_title("2. LOOKUP TECHNIQUES (EQUAL_RANGE, COUNT, FIND)");

    // C++20 contains() check
    std::cout << "Set contains 40? " << (mset.contains(40) ? "Yes" : "No") << "\n";

    // count() tells you EXACTLY how many matching instances exist
    std::cout << "Occurrences of item 40: " << mset.count(40) << "\n";
    std::cout << "Occurrences of item 10: " << mset.count(10) << "\n";

    // find() points to the VERY FIRST instance found matching the key criteria
    auto find_it = mset.find(40);
    if (find_it != mset.end()) {
        std::cout << "find(40) matched item value: " << *find_it << "\n";
    }

    // equal_range() yields a std::pair of iterators tracking the continuous boundary match block
    auto [lower_bound, upper_bound] = mset.equal_range(40);
    std::cout << "Iterating over equal_range(40) subrange values: ";
    for (auto bit = lower_bound; bit != upper_bound; ++bit) {
        std::cout << *bit << " ";
    }
    std::cout << "\n";

    // =========================================================================
    // 3. TARGETED REMOVALS & DESTRUCTIONS (C++17 Node Handles)
    // =========================================================================
    print_title("3. REMOVAL MECHANICS & ZERO-COPY EXTRACTS");

    // CRUCIAL NOTE on erase(key): Erasing by a value removes ALL matching duplicates!
    std::size_t removed_count = mset.erase(10); 
    std::cout << "Total 10s deleted globally via value erasure: " << removed_count << "\n";

    // To remove only a SINGLE matching instance among duplicates, erase via an iterator position:
    auto instance_it = mset.find(40);
    if (instance_it != mset.end()) {
        mset.erase(instance_it); // Only deletes this single 40 node instance
    }
    std::cout << "Occurrences of item 40 remaining after single iterator delete: " << mset.count(40) << "\n";

    // C++17 extract() unlinks one single node instance cleanly for structural mutation without copying
    std::unordered_multiset<int>::node_type individual_node = mset.extract(40);
    if (!individual_node.empty()) {
        individual_node.value() = 42; // Change value safely while unlinked from container
        mset.insert(std::move(individual_node)); // Re-insert it
    }

    std::unordered_multiset<int> tracking_sink = {900, 1000};
    mset.merge(tracking_sink); // Splices compatible nodes from tracking_sink straight over
    std::cout << "Size of mset after merging tracking_sink data: " << mset.size() << "\n";

    // =========================================================================
    // 4. BUCKET INTERNAL DETAILS & SYSTEM SCHEDULER POLICIES
    // =========================================================================
    print_title("4. INTERNAL BUCKET GRID DIAGNOSTICS");

    std::cout << "Total Allocation Buckets: " << mset.bucket_count() << "\n";
    std::cout << "Current Map Load Factor: " << mset.load_factor() << "\n";
    std::cout << "Max density limit configuration: " << mset.max_load_factor() << "\n";

    int sample_key = 42;
    auto bucket_index = mset.bucket(sample_key);
    std::cout << "Key (" << sample_key << ") sits inside Bucket Channel ID: #" << bucket_index << "\n";
    std::cout << "Bucket #" << bucket_index << " collision density node size: " << mset.bucket_size(bucket_index) << "\n";

    // Step loop through elements within a single collision tracking bucket
    std::cout << "Items currently sharing Bucket #" << bucket_index << ": ";
    for (auto bit = mset.cbegin(bucket_index); bit != mset.cend(bucket_index); ++bit) {
        std::cout << *bit << " ";
    }
    std::cout << "\n";

    // Optimization Tuning Policies
    mset.reserve(100); // Forces hash layout reallocation strategy ahead of heavy insertion load spikes
    std::cout << "Bucket structure layout update count following reserve(100): " << mset.bucket_count() << "\n";

    // =========================================================================
    // 5. COMPLEX TYPE PACKAGING (Custom Hash Custom Equality)
    // =========================================================================
    print_title("5. CUSTOM TYPE MULTI-SET BINDINGS");

    std::unordered_multiset<LogEntry, LogHasher, std::equal_to<LogEntry>> log_vault;

    log_vault.insert(LogEntry{505, "Connection Timeout Error"});
    log_vault.insert(LogEntry{404, "Page Not Found Error"});
    log_vault.insert(LogEntry{505, "Another Connection Timeout Instance"}); // Stored completely as duplicate node

    std::cout << "Total stored Log Registry records: " << log_vault.size() << "\n";
    for (const auto& log : log_vault) {
        std::cout << " -> [Error Code Code: " << log.error_code << "] Msg: " << log.message << "\n";
    }

    // =========================================================================
    // 6. GLOBAL UNIFORM CLEANUP
    // =========================================================================
    print_title("6. SYSTEM SANITIZATION & FINAL CLEAR");

    // C++20 non-member std::erase_if function handles multi-instance arrays safely
    std::erase_if(mset, [](int x) { return x > 100; }); // Safely purge all merged entries > 100
    
    std::cout << "Final collection readout before wipe: [ ";
    for (auto it = mset.cbegin(); it != mset.cend(); ++it) std::cout << *it << " ";
    std::cout << "]\n";

    mset.clear(); // Wipes the whole layout clean
    std::cout << "Wipe sequence confirmation. Container size remaining: " << mset.size() << "\n";

    return 0;
}

