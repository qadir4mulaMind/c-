#include<iostream>
#include<string>
#include<sstream>

void test0(){
  std::string st = "Hi everyone my name is Abdul Qadir.";
  std::stringstream ss(st);
  std::cout << ss.str() << std::endl;
  
  std::string chunk;
  while(ss >> chunk){
    std::cout << chunk << std::endl;
    std::cout << ss.tellg() << std::endl;
  }

  std::cout << std::endl;

  ss.seekg(0, std::ios_base::beg);
  std::cout << ss.fail() << std::endl;
  ss.clear();

  st += "Can you please help me";
  while(ss >> chunk){
    std::cout << chunk << std::endl;
  }
}

int main(){
  test0();
  return 0;
}
