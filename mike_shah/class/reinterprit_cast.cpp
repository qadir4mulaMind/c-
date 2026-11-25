#include<iostream>

int main(){
  float pi = 3.14159;

  std::cout << *reinterpret_cast<int*>(&pi) << std::endl;
  std::cout << *reinterpret_cast<float*>(&pi) << std::endl;
  return 0;
}
