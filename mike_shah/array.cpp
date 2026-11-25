#include<iostream>
#include<numeric>
#include<iterator>
#include<array>

int main(){
  int ids[10];
  
  std::iota(std::begin(ids), std::end(ids), 0);
  
  for(auto x: ids){
    std::cout << x << std::endl;
  }
  
  std::array<int, 10> arr;
  std::iota(std::begin(arr), std::end(arr), 0);
  arr.at(200) = 9;
  
  for(auto x: arr){
    std::cout << x << std::endl;
  }

  return 0;
}
