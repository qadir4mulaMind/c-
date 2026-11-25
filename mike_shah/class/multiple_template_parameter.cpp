#include<iostream>
#include<typeinfo>

template <typename T1, size_t N>

void foo(T1 input1){
  std::cout << typeid(input1).name() << std::endl;
  std::cout << typeid(N).name() << std::endl;
}

int main(){
  foo<int, 5>(5);
  return 0;
}
