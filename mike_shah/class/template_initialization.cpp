#include<iostream>
#include<typeinfo>

template<typename T>
bool equal(T a, T b){
  return (a == b);
}


int main(){
  std::cout << equal<int>(2, 2) << std::endl;
  std::cout << equal<int>(2, 3) << std::endl;
  std::cout << equal<int>(1.0f - 0.999999f, 0.000001f) << std::endl;
  return 0;
}
