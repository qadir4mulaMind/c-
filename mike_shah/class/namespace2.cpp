#include<iostream>
typedef void void_tt;
void_tt foo(){
  using std::cout;
  cout << "will this work\n";
}

int main(){
  using std::cout;
  cout << "Heh??\n";
  foo();
  return 0;
}
