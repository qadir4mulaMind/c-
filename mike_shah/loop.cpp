#include<iostream>
#include<array>
int main(){
  std::array<int, 5> arr{1, 2, 3, 4, 5};  

  for(int& x : arr){
    std::cout << x << std::endl;
  }
  
  std::array<int, 6> arr2;
  std::fill(std::begin(arr2), std::end(arr2), 1024);

  for(int& x : arr2){
     std::cout << x << std::endl;
  }

  return 0;
}
