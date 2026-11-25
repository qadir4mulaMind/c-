#include<iostream>
auto add(float, float) -> float;

int main(){

std::cout << add(5.3f, 1.6f) << std::endl; 

  return   0;
}

float add(float a, float b){
  return a + b;
}
