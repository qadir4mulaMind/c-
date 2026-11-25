#include<iostream>

void print_string(const std::string& param){
  std::cout << param << std::endl;
}

int main(){

  const char* s = "This is really a long string...........";
  print_string(s);
  return 0;
}
