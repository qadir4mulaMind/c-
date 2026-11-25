#include<iostream>

int main(){
  int* x =  new int;
  *x = 42;

  delete x; 
  delete x;
  return 0;
}
