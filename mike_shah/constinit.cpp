#include<iostream>

constexpr int exp1(){
  return 42;
}

constexpr int expr2(){
  return 42;
}

consteval int expr3(){
  return 43;
}

int main(){
  constinit static int var1 = 7;
  return 0;
}
