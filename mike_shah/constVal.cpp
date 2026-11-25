#include<iostream>

constexpr auto add1 = [](int a, int b){
  return a + b;
};
consteval int add2(int a, int b){
  return a + b;
}

int main(){
  std::cout << add1(2, 3) << std::endl;
  std::cout << add2(2, 3) << std::endl;
}
