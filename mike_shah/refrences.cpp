#include<iostream>
#include<typeinfo>

int main(){
  int x = 21;
  int& y = x;

  std::cout << "x: " << x << std::endl;
  std::cout << "x type: " << typeid(x).name() << std::endl;
  std::cout << "y: " << y << std::endl;
  std::cout << "y type: " << typeid(y).name() << std::endl;

  // int& z; => refrence is always for existing;

  int* f = nullptr;
  std::cout << "f type: " << typeid(f).name() << std::endl;
  int*& w = f;
  std::cout << "w type: " << typeid(w).name() << std::endl;
  return 0;
}
