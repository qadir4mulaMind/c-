#include<iostream>

template <typename T1, typename T2>

void foo(T1 input1, T2 input2){
  std::cout << input1 << std::endl;
  std::cout << input2 << std::endl;
}

int main(){
  foo1(5, 6.5);
  return 0;
}
