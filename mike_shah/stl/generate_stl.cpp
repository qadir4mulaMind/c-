#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

void test0(){
  std::vector<int> v1;

  for(int i = 0; i < 30; i++){
    v1.push_back(i);
  }

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
}

int f(){
  static int i = 0;
   return i++;
}

int g(int i){
  return i * 2;
}

void test1(){
  std::vector<int> v1(30);
  std::generate(begin(v1), end(v1), [n = 0]() mutable {
      return n++;
      });

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
}
int main(){
  test0();
  
  std::vector<int> v1(10);
  std::generate(begin(v1), end(v1), f);

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;

  std::cout << "--------------------------------" << std::endl;


  std::vector<int> v2;
  v2.resize(30);
  
  std::generate(begin(v2), end(v2), [n = 0]() mutable {
      return n++;
      });
  
  for(const auto& ele : v2){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
  std::cout << "--------------------------------" << std::endl;

  std::vector<int> v3(30);
  std::generate(begin(v3), end(v3), [n = 0]() mutable {
      return g(n++);
      });

  for(const auto& ele : v3){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
  std::cout << "--------------------------------" << std::endl;
  test1();
  return 0;
}
