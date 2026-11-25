#include<iostream>
#include<string>

int main(){

  std::string s1 = "Mike";
  std::string s2 = "This is really a very long value";
  std::string&& x = s1 + s2;
  return 0;
}
