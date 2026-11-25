#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<iterator>

void test0(){
  std::string s1 = "HELLO my WORLD!";
  std::string s2;

  std::copy_if(s1.begin(), s1.end(), std::back_inserter(s2), [](char c){
      return (c > 64 && c < 91) || c ==  ' ';
      });

  std::cout << s2 << std::endl;
}

void test1(){
  std::string s1 = "HELLO my WORLD!";
  std::string s2;

  std::copy_n(s1.begin() + 6, s1.length() -6, std::back_inserter(s2));

  std::cout << s2 << std::endl;
}

int main(){
  test0();
  std::cout << "--------------------------" << std::endl;
  test1();
  return 0;
}
