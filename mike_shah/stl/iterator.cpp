#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>


int main(){
  std::vector<int> v1{1, 2, 3, 4, 5};

  for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  for(auto it = v1.begin(); it != v1.end(); ++it){
    std::cout << *it << " " << std::endl;
  }
  std::cout << std::endl;

  for(auto v : v1){
    std::cout << v << " " << std::endl;
  }
  std::cout << " " << std::endl;

  auto it = v1.begin();
  for(std::advance(it, 2); it != v1.end(); ++it){
    std::cout << *it << " " <<  std::endl;
  }

  return  0;
}

