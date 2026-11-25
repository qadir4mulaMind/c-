#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

// Aapka signature style: Universal reusable auto print lambda
auto print = [](const auto& container) {
  for (const auto& ele : container) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

// Test 0: Inclusive Scan Demonstration (Includes current element)
void test0() {
  std::vector v1{1, 2, 3, 4, 5}; // C++17 CTAD style
  std::vector<int> result;
  
  std::cout << "v1 original: ";
  print(v1);

  // Inclusive Scan: 1, (1+2), (1+2+3), ...
  std::inclusive_scan(v1.begin(), v1.end(), std::back_inserter(result));

  std::cout << "Inclusive scan output: ";
  print(result);
  std::cout << "--------------------------------" << std::endl;
}

// Test 1: Exclusive Scan Demonstration (Excludes current element, uses initial seed)
void test1() {
  std::vector v1{1, 2, 3, 4, 5};
  std::vector<int> result;

  std::cout << "v1 original: ";
  print(v1);

  // Exclusive Scan: Initial value (0) se shuru karega aur current element ko chhodega
  // 0, (0+1), (0+1+2), (0+1+2+3), ...
  std::exclusive_scan(v1.begin(), v1.end(), std::back_inserter(result), 0);

  std::cout << "Exclusive scan output (seed = 0): ";
  print(result);
}

int main() {
  std::cout << "=== Running test0 ===" << std::endl;
  test0();
  std::cout << "=== Running test1 ===" << std::endl;
  test1();
  return 0;
}

