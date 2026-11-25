#include<iostream>

template<typename T>
T square(T input){
   return input * input;
}

int main(){
  std::cout << square<int>(5) << std::endl;
  std::cout << square<double>(5.5) << std::endl;
  std::cout << square<float>(5.6f) << std::endl;
  return 0;
}
