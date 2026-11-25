#include<iostream>
#include<source_location>

int add(int a, int b){
  std::source_location location = std::source_location::current();
  std::cout << location.line() << std::endl;
  return a + b;
}

int main(){

  return 0;
}
