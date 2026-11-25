#include<iostream>

int* returnMemory(){
  int result = 91;
  return &result;
}

int main(){
  int* px = returnMemory();

  std::cout << *px << std::endl;
  return 0;
}
