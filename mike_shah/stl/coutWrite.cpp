#include<iostream>

int main(){
  std::cout.write("Hello world!\n", 13);
  std::cout << std::hex << 1234 << std::endl;
  bool a = true;
  std::cout << std::boolalpha << a << std::endl;
  return 0;
}
