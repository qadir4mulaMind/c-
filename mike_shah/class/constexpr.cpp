#include<iostream>

constexpr int add(int a, int b){
  return a + b;
}

int main(){

  constexpr int i = add(7, 16); // 23

  return 0;
}

