#include<iostream>
#include "inline_variable.hpp"

int main(){
  Struct s;
  Struct::someVal = 94;
  std::cout << Struct::someVal << " SomeValue\n";
  return 0;
}
