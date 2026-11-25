#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>
#include <utility>
#include <algorithm>

// ============================================================================
// SYSTEM TYPE: CUSTOM STRUCT KEY & AUTOMATED COMPARISON ENGINE
// ============================================================================
struct DeviceKey {
    int id;
    std::string model;

    // C++20 spaceships operator automatically fulfills Strict Weak Ordering 
    // (!comp(a, b) && !comp(b, a)) for maps by checking fields lexicographically
    auto operator<=>(const DeviceKey& other) const = default;
};

// Console formatting block logging helper
void print_title(std::string_view title) {
    std::cout << "\n=======================================================\n"
              << " " << title << "\n"
              << "=======================================================\n";
}

int main() {
    // =========================================================================
    // 1. INITIALIZATION & MODIFIERS (Insertions, Emplace & Ranges)
    // =========================================================================
    print_title("1. INITIALIZATION & ELEMENT MODIFIERS");

    // Standard constructor syntax using braced initializers
    std::map<std::string, int> hardware_map = {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    
    std::cout << "Is container empty? " << (hardware_map.empty() ? "Yes" : "No") << "\n";
    std::cout << "Total elements stored: " << hardware_map.size() << "\n";
    std::cout << "System limit boundary capacity: " << hardware_map.max_size() << "\n\n";

    // Modifying elements via subscript operator and at() boundaries
    hardware_map["CPU"] = 25;       // Overwrites existing payload element
    hardware_map["SSD"] = 30;       // Inserts a brand new key automatically
    hardware_map.at("RAM") = 22;    // Safe modification (throws std::out_of_range if missing)

    // C++17 insert_or_assign to safely determine action flow
    auto [ioa_it, ioa_success] = hardware_map.insert_or_assign("GPU", 18);
    std::cout << "insert_or_assign GPU success status: " << std::boolalpha << ioa_success << "\n";

    // try_emplace leaves arguments untouched if the designated key already exists
    auto [te_it, te_success] = hardware_map.try_emplace("CPU", 99);
    std::cout << "try_emplace CPU (already exists) inserted status: " << te_success << "\n";

    // emplace and emplace_hint building structural pairs down in memory tables
    hardware_map.emplace("NIC", 5);
    hardware_map.emplace_hint(hardware_map.begin(), "PSU", 8);

    // C++23 insert_range() updating elements straight out of compatible standard vectors
    std::vector<std::pair<std::string, int>> promotional_batch = {{"Cooler", 12}, {"Case", 14}};
    hardware_map.insert_range(promotional_batch);

    std::cout << "\nCurrent Map elements (Sorted automatically by ascending keys):\n";
    for (const auto& [key, value] : hardware_map) {
        std::cout << "  [" << key << "] = " << value << "\n";
    }

    // =========================================================================
    // 2. ADVANCED LOOKUP MECHANICS (BOUNDARIES & METRICS)
    // =========================================================================
    print_title("2. LOOKUP TECHNIQUES (CONTAINS, BOUNDS, SEARCH)");

    // C++20 contains() check
    std::cout << "Map contains \"SSD\"? " << (hardware_map.contains("SSD") ? "Yes" : "No") << "\n";
    std::cout << "Total key counts for \"CPU\": " << hardware_map.count("CPU") << "\n\n";

    // find() targeting elements without index instantiation penalties
    auto find_it = hardware_map.find("RAM");
    if (find_it != hardware_map.end()) {
        std::cout << "find(\"RAM\") points directly to value: " << find_it->second << "\n";
    }

    // boundary lookups: lower_bound & upper_bound exploration
    auto lb_it = hardware_map.lower_bound("GPU"); // First element not less than "GPU"
    auto ub_it = hardware_map.upper_bound("GPU"); // First element strictly greater than "GPU"
    std::cout << "lower_bound(\"GPU\") points to: [" << lb_it->first << " -> " << lb_it->second << "]\n";
    std::cout << "upper_bound(\"GPU\") points to: [" << ub_it->first << " -> " << ub_it->second << "]\n";

    // equal_range maps tracking subrange blocks cleanly in standard pairs
    auto [lower, upper] = hardware_map.equal_range("NIC");

    // =========================================================================
    // 3. ZERO-COPY EXTRACTS & NODE MANIPULATIONS (C++17 Node Handles)
    // =========================================================================
    print_title("3. REMOVAL MECHANICS & ZERO-COPY NODES");

    // Basic targeted key erasure
    std::size_t erased_count = hardware_map.erase("NIC");
    std::cout << "Total \"NIC\" elements removed via key erasure: " << erased_count << "\n";

    // C++17 extract() unlinks a node from the allocation table cleanly for mutation without copy penalties
    std::map<std::string, int>::node_type unlinked_node = hardware_map.extract("SSD");
    if (!unlinked_node.empty()) {
        unlinked_node.key() = "NVMe_SSD"; // Change key value safely while detached from internal tree sorting constraints
        hardware_map.insert(std::move(unlinked_node)); // Re-insert it into position
        std::cout << "Successfully changed extracted node key index to \"NVMe_SSD\"\n";
    }

    // Merging containers: Splicing compatible node tracking systems down across maps seamlessly
    std::map<std::string, int> buffer_source = {{"Motherboard", 50}, {"CPU", 999}};
    hardware_map.merge(buffer_source); // Elements with duplicate keys (e.g. CPU) stay untouched in source map
    std::cout << "Size of primary hardware map after splicing data via .merge(): " << hardware_map.size() << "\n";

    // =========================================================================
    // 4. COMPLEX STRUCT OVERLOAD COMPARISONS & SYSTEM STRATEGY POLICIES
    // =========================================================================
    print_title("4. CUSTOM STYLED KEYS & COMPARATOR OBSERVERS");

    std::map<DeviceKey, std::string> device_registry;
    device_registry[DeviceKey{101, "ThinkPad"}] = "Workstation Alpha";
    device_registry[DeviceKey{102, "MacBook"}]  = "Creative Node Beta";

    std::cout << "Total customized structural records matching registry: " << device_registry.size() << "\n";

    // Verification of standard observer logic objects
    auto key_kernel_comp = hardware_map.key_comp();
    auto value_kernel_comp = hardware_map.value_comp();

    std::cout << "Observer test: Is \"Case\" sorted before \"Cooler\"? " 
              << key_kernel_comp("Case", "Cooler") << "\n";

    // =========================================================================
    // 5. GLOBAL UNIFORM CLEANUP
    // =========================================================================
    print_title("5. C++20 SYSTEM SANITIZATION & FINAL WIPES");

    // C++20 non-member std::erase_if function predicate loop drops
    std::erase_if(hardware_map, [](const auto& pair) {
        return pair.second > 25; // Drop structural equipment objects reporting over a certain density limit threshold
    });

    std::cout << "Final map collection status values before execution termination:\n";
    for (auto rit = hardware_map.crbegin(); rit != hardware_map.crend(); ++rit) {
        std::cout << "  * [" << rit->first << " : " << rit->second << "]\n";
    }

    hardware_map.clear(); // Complete allocation wipe
    std::cout << "\nWipe sequence confirmed. Active allocation size remaining: " << hardware_map.size() << "\n";

    return 0;
}

