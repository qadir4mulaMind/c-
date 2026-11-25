#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

auto print = [](const auto& c, const char* msg){
  std::cout << msg << ":";
  for(const auto& ele : c){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector<int> v1{1, 2, 2, 3, 3, 3, 3, 4, 5, 6, 7};
  print(v1, "Original");

  auto it = std::unique(v1.begin(), v1.end());
  v1.erase(it, v1.end());
  print(v1, "Unique");
}

void test1(){
  std::string s = "hello world !!!!";
  std::string out;
  std::unique_copy(begin(s), end(s), std::back_inserter(out), [](char c1, char c2){
      if(c1 == ' ' && c2 == ' '){
        return true;
      }
      return false;
      });
  std::cout << "Original String: " << s << std::endl;
  std::cout << "out string: " << out << std::endl;
}


int main(){
  test0();
  test1();
  return 0;
}
