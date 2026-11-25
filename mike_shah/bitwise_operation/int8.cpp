#include<iostream>

int main(){
  int8_t x = 16;
  int8_t y = 0b0111;

  std::cout << (int)x << " " << (int)y << std::endl;

  std::cout << std::hex << (int)x << std::endl;
  std::cout << std::format("{:b}", y) << std::endl;

  return 0;
}
