#include<iostream>
#include<string>

void test0(){
  std::string exp1 = "45";
  std::string exp2 = "90";
  std::string exp3 = "5.5";
  std::string base16 = "A0";


  std::cout << exp1 << std::endl;
  std::cout << exp2 << std::endl;
  std::cout << exp3 << std::endl;
  std::cout << base16 << std::endl;

  std::cout << "==============================" << std::endl;

  std::cout << std::stoi(exp1) << std::endl;
  std::cout << std::stoi(exp2) << std::endl;
  std::cout << std::stoi(exp3) << std::endl;
  std::cout << std::stoi(base16, nullptr, 16) << std::endl;

  std::cout << "==============================" << std::endl;
  std::cout << std::to_string(13.5f) << std::endl; 

}

int main(){
  test0();
  return 0;
}
