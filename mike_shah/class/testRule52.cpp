#include<iostream>
#include "rule52.hpp"
#include<vector>
#include <string>

void foo(IntArray temp){

}

int main(){
  std::vector<IntArray> arr1;
  arr1.reserve(10);
  for(int i = 0; i < 10; i++){
    IntArray temp(std::to_string(i));
    arr1.push_back(std::move(temp));
  }
  return 0;
}
