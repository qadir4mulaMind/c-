#include<iostream>
#include<iterator>
#include<string>
#include<algorithm>

void test0(){
  std::string s = "mike";
  std::string out;

  std::transform(s.begin(), s.end(), std::back_inserter(out), [](unsigned char c){
    return std::toupper(c);
    });
  
  std::cout << s << std::endl;
  std::cout << out << std::endl;
}

void test1(){
  std::string s = "qadir";

  std::cout << s << std::endl;

  std::transform(s.begin(), s.end(), s.begin(), [](const unsigned char& c){
      return std::toupper(c);
      });

  std::cout << s << std::endl;
}

int main(){
  test0();
  test1();
  return 0;
}
