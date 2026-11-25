#include<iostream>
#include "person.hpp"

int main(){

  Person mike("mike");
  std::cout << mike.getAttributes() << std::endl;

  return 0;
}
