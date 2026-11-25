#include<iostream>
//#define PI 3.1415926
constexpr float PI = 3.141526
#define DEBUG 1

int main(){

#if DEBUG
  std::cout << PI << std::endl;
#else
  std::cout << "not debug\n";
#endif
  return 0;
}
