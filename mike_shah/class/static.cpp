#include<iostream>

void foo(){
  static int s_variable = 0;
  s_variable += 1;
  
  std::cout << s_variable << std::endl;
}


int main(){
  for(int i = 0; i < 10; i++){
    foo();
  }

  return 0;
}


