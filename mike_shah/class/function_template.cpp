#include<iostream>

auto square2(auto x){
  return x * x;
}

int main(){
  
  std::cout << square2(5) << std::endl;
  std::cout << square2(6.5f) << std::endl;
  return 0;
}
