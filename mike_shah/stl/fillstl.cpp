#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<forward_list>

void test0(){
  std::vector<int> v1;
  v1.reserve(50);
  
  for(int i = 0; i < 50; i++){
    v1.push_back(100);
  }

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}

void test1(){
  std::vector<int> v1(50);

  std::fill(begin(v1), end(v1), 100);

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;

  std::vector<int> v2(50);

  std::fill(v2.begin(), v2.end(), -2);

  for(const auto & ele : v2){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}

void test2(){
  std::vector<int> v1(50);

  std::fill_n(v1.begin(), 5, 8);

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
}

void test3(){
  std::forward_list<int> v1(50);

  std::fill(begin(v1), end(v1), 100);

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;

  std::vector<int> v2(50);

  std::fill(v2.begin(), v2.end(), -2);

  for(const auto & ele : v2){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}


int main(){
  test0();
  std::cout << "-----------------------------" << std::endl;
  test1();
  std::cout << "-----------------------------" << std::endl;
  test2();
  std::cout << "-----------------------------" << std::endl;
  test3();
  return 0;
}
