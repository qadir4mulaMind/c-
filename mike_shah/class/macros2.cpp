#include<iostream>
#define LOG(param) std::cout << "LOG\n" \
                             << #param; \
                             param; \
                            std::cout << std::endl;

int add(int a, int b){
  return a + b;
}

int main(){
 LOG(add(7, 2););
#ifdef DEBUG
  std::cout << PI << std::endl;
#else
  std::cout << 22.0f / 7.0f << std::endl;;
#endif
  return 0;
}
