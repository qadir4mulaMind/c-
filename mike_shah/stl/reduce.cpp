#include <iostream>
#include <numeric>
#include <vector>
#include <execution>

void test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};

  // 1. Normal Sequential Reduce (Yeh hamesha chalega)
  std::cout << "v1 Sequential: " << std::reduce(v1.begin(), v1.end(), 0) << std::endl;

  // 2. Parallel Reduce with safe compilation check
  #if defined(__cpp_lib_parallel_algorithm)
    std::cout << "v1 Parallel: " << std::reduce(std::execution::par, v1.begin(), v1.end(), 0) << std::endl;
  #else
    std::cout << "Parallel feature not supported by libc++, using fallback." << std::endl;
    std::cout << "v1 Fallback: " << std::reduce(v1.begin(), v1.end(), 0) << std::endl;
  #endif
}

int main(){
  test0();
  return 0;
}

