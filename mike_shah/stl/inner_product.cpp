#include<iostream>
#include<array>
#include<numeric>
#include<functional>

void test0(){
  std::array<int, 5> a{0, 1, 2, 3, 4};
  std::array b{5, 4, 2, 3, 1};

  auto sum_of_product = std::inner_product(a.begin(), a.end(), b.begin(), 0);
  std::cout << "Sum of product: " << sum_of_product << std::endl;
}

void test1(){
  std::array<int, 5> a{0, 1, 2, 3, 4};
  std::array b{5, 4, 2, 3, 1};

  auto sum_of_product = std::inner_product(a.begin(), a.end(), b.begin(), 0, std::plus<>(), std::multiplies<>());
  std::cout << "Sum of product: " << sum_of_product << std::endl;
}



int main(){
  test0();
  test1();
  return 0;
}
