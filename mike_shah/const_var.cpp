#include<iostream>
#include<type_traits>

int main(){
  const int x = 43;
  std::cout << "x: " << x << std::endl;

  // x = 21;
  // std::cout << "x: " << x << std::endl;

  std::cout << std::is_const_v<int> <<  std::endl;
  std::cout << std::is_const_v<const int> << std::endl;
  std::cout << std::is_const<decltype(x)>::value << std::endl; 
  return 0;
}
