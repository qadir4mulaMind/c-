#include<iostream>

void foo(){
  using std::cout;
  cout << "will this work\n";
}

int main(){
  using std::cout;
  cout << "Heh??\n";
  foo();
  return 0;
}
