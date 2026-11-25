#include<iostream>
#include<cassert>


int main(){

  int age = -7;
  
  assert(age > 0 && "age was greater than 0");

  static_assert(age > 0 && "Message");

  return 0;
}
