#include<iostream>

union U{
  int i;
  short s;
  float f;
};

int main(){
  U u1;
  u1.i = 50;
  std::cout << u1.i << std::endl;
  u1.s = 40;
  std::cout << u1.s << std::endl;
  return 0;
}

