#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

// ============================================================================
// CUSTOM CLASS & HASHING (Advanced Setup)
// ============================================================================
struct Employee {
    int id;
    std::string name;

    // Do employees equal hain ya nahi, yeh check karne ke liye operator
    bool operator==(const Employee& other) const {
        return id == other.id; 
    }
};

// Custom Hash nikalne ka tareeqa (Functor)
struct EmployeeHasher {
    std::size_t operator()(const Employee& e) const {
        return std::hash<int>{}(e.id) ^ (std::hash<std::string>{}(e.name) << 1);
    }
};

// Section logging helper
void print_title(std::string_view title) {
    std::cout << "\n>>> " << title << " <<<\n";
}

int main() {
    // =========================================================================
    // 1. INITIALIZATION & BASIC MODIFIERS
    // =========================================================================
    print_title("1. INITIALIZATION & INSERTIONS");

    // Initializer list (Duplicate 20 automatic delete ho jayega)
    std::unordered_set<int> mySet = {40, 10, 20, 30, 20}; 
    
    std::cout << "Kya set khali hai? " << (mySet.empty() ? "Haan" : "Nahi") << "\n";
    std::cout << "Set ka current size: " << mySet.size() << "\n";

    // Standard Insert (Yeh ek pair return karta hai: iterator aur success status)
    auto [position, success] = mySet.insert(50);
    std::cout << "Kya 50 insert hua? " << (success ? "Haan" : "Nahi") << "\n";

    // Emplace (Direct in-place object construct karta hai)
    mySet.emplace(60);

    // C++23 insert_range (Pura vector ek sath insert karne ke liye)
    std::vector<int> new_numbers = {70, 80, 90};
    mySet.insert_range(new_numbers);

    std::cout << "Set ke saare elements: ";
    for (int x : mySet) std::cout << x << " ";
    std::cout << "\n";

    // =========================================================================
    // 2. LOOKUP OPERATIONS (Elements Dhoondna)
    // =========================================================================
    print_title("2. LOOKUP (SEARCHING) METHODS");

    // C++20 contains() - Sabse aasan tareeqa check karne ka
    if (mySet.contains(70)) {
        std::cout << "Element 70 set me maujood hai!\n";
    }

    // Classic find() - Iterator return karta hai
    auto find_it = mySet.find(30);
    if (find_it != mySet.end()) {
        std::cout << "find() se element mila: " << *find_it << "\n";
    }

    // count() - Set me unique elements hote hain, isliye yeh ya to 0 dega ya 1
    std::cout << "99 ka count set me: " << mySet.count(99) << "\n";

    // =========================================================================
    // 3. ERASURES & NODE MANIPULATION (C++17)
    // =========================================================================
    print_title("3. ERASING & NODE MANIPULATION");

    // Value se erase karna
    mySet.erase(10); 

    // C++17 extract() - Bina memory copy kiye element ko set se bahar nikalna
    // Isse aap value ko modify karke wapas dal sakte hain safely
    auto node_handle = mySet.extract(40);
    if (!node_handle.empty()) {
        node_handle.value() = 45; // 40 ko badal kar 45 kiya
        mySet.insert(std::move(node_handle)); // Wapas insert kar diya
    }

    std::cout << "Modifications ke baad set: [ ";
    for (auto it = mySet.cbegin(); it != mySet.cend(); ++it) std::cout << *it << " ";
    std::cout << "]\n";

    // =========================================================================
    // 4. BUCKET INTERFACE & HASH METRICS
    // =========================================================================
    print_title("4. BUCKET INTERFACE & HASH POLICIES");

    std::cout << "Total Buckets (Chambers): " << mySet.bucket_count() << "\n";
    std::cout << "Current Load Factor: " << mySet.load_factor() << "\n";
    std::cout << "Max Load Factor Limit: " << mySet.max_load_factor() << "\n";

    int check_key = 45;
    auto bucket_index = mySet.bucket(check_key);
    std::cout << "Key (" << check_key << ") Bucket #" << bucket_index << " me baithi hai.\n";
    std::cout << "Bucket #" << bucket_index << " ka size: " << mySet.bucket_size(bucket_index) << "\n";

    // Ek specific bucket ke andar loop chalana (Local Iteration)
    std::cout << "Bucket #" << bucket_index << " ke saare elements: ";
    for (auto bit = mySet.cbegin(bucket_index); bit != mySet.cend(bucket_index); ++bit) {
        std::cout << *bit << " ";
    }
    std::cout << "\n";

    // Memory sizing optimization (Rehash se bachne ke liye)
    mySet.reserve(150); 
    std::cout << "reserve(150) ke baad new bucket count: " << mySet.bucket_count() << "\n";

    // =========================================================================
    // 5. CUSTOM TYPE INTEGRATION
    // =========================================================================
    print_title("5. CUSTOM TYPE (STRUCT/CLASS) IN SET");

    // Custom struct, custom hasher aur custom equality function ke sath set
    std::unordered_set<Employee, EmployeeHasher, std::equal_to<Employee>> registry;
    
    registry.insert(Employee{101, "Rahul"});
    registry.insert(Employee{102, "Amit"});
    registry.insert(Employee{101, "Duplicate Rahul"}); // Yeh skip ho jayega kyunki ID 101 pehle se hai

    std::cout << "Registry ka size: " << registry.size() << "\n";
    for (const auto& emp : registry) {
        std::cout << "ID: " << emp.id << " | Name: " << emp.name << "\n";
    }

    // =========================================================================
    // 6. GLOBAL CLEANUP
    // =========================================================================
    print_title("6. CLEANUP & DESTRUCTION");

    // C++20 std::erase_if (Ek condition ke basis par set se elements urana)
    std::erase_if(mySet, [](int x) { return x > 60; }); // 60 se bade saare numbers delete
    std::cout << "erase_if ke baad size: " << mySet.size() << "\n";

    // Pura set saaf karna
    mySet.clear();
    std::cout << "clear() ke baad final size: " << mySet.size() << "\n";

    return 0;
}

