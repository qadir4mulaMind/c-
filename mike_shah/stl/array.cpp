#include<iostream>

int main(){

  std::array<int, 5> data = {1, 2, 3, 4, 5};
  std::array<int, 6> d2;
  d2.fill(0);
  std::cout << data.at(4) << std::endl;
  std::cout << d2[3] << std::endl;

  return 0;
}
