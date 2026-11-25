#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

void test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};

  std::vector<int> v1_copy;

  std::copy(v1.cbegin(), v1.cend(), std::back_inserter(v1_copy)); 

  for(auto& elem : v1_copy){
    std::cout << elem << std::endl;
  }
}

void test1(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};

  std::vector<int> v1_copy;

  std::copy(v1.rbegin(), v1.rend(), std::back_inserter(v1_copy));

  for(auto& elem : v1_copy){
    std::cout << elem << std::endl;
  }

  std::cout << std::endl;

  std::vector<int> v2;
  v2.reserve(v1.size());

  auto res = std::copy(v1.begin(), v1.end(), std::back_inserter(v2));

  for(auto& ele : v2){
    std::cout << ele << std::endl;
  }
}

void test2(){
  std::vector<int> v(10000000);
  std::iota(v.begin(), v.end(), 1);
  for(auto& ele : v){
    std::cout << ele << " ";
  }
}
  


int main(){
  test0();
  std::cout << std::endl;
  test1();
  std::cout << std::endl;
  test2();
  return 0;
}
