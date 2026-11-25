#include<iostream>

void foo(){
//  c = 10
}

int main(){
  
  int x = 12;
  float y = 23;
  char c = 'g';
  signed char d = 'h';
  unsigned char e = 'i';

  std::cout << "x: " << &x << std::endl;
  std::cout << "x: " << &(x) << std::endl;
  std::cout << "x' size: " << sizeof(x) <<  std::endl;
  std::cout << "y: " << &y << std::endl;
  std::cout << "y: " << (void*)&y << std::endl;
  std::cout << "c: " << &c << std::endl;
  std::cout << "c: " << &(c) << std::endl;
  std::cout << "c: " << (void*)&c << std::endl;
  std::cout << "d: " <<  &d << std::endl;
  std::cout << "d: " <<  (void*)&d << std::endl;
  std::cout << "e: " <<  &e << std::endl;
  std::cout << "e: " <<  (void*)&e << std::endl;
  std::cout << "foo: " << &foo << std::endl;
  std::cout << "foo: " << (void*)&foo << std::endl;

  std::cout << "main: " << &main << std::endl;
  std::cout << "main: " << (void*)&main << std::endl;

  return 0;
}
