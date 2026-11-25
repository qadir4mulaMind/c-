#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  
  // 1. Corrected loop condition from '<' to '!=' (Best Practice)
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << "\n";
  }

  std::cout << "\n";

  std::vector<long> v2;
  v2.reserve(50);

  for (std::vector<long>::iterator it = v2.begin(); it != v2.end(); it++) {
    std::cout << *it << "\n";
  }

  std::cout << "\n";

  // (Original range-based loop caused iterator invalidation/undefined behavior)
  while (!v.empty()) {
    int x = v.front();
    v.erase(v.begin());
    std::cout << x << "\n";
  }

  return 0;
  }

