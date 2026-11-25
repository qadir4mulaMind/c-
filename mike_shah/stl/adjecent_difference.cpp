#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> 

auto print = [](const auto& c){
  for(const auto& ele : c){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector<int> v1{7, 5, 1, 3, 9, 2};
  std::vector<int> result; 
  print(v1);

  std::adjacent_difference(v1.begin(), v1.end(), std::back_inserter(result));

  print(result);
}

void test1(){
  std::vector<int> v1{7, 5, 1, 3, 9, 2};
  print(v1);

  std::adjacent_difference(v1.begin(), v1.end(), v1.begin());

  print(v1);
}

int main(){
  std::cout << "--- test0 Output ---" << std::endl;
  test0();
  std::cout << "--- test1 Output ---" << std::endl;
  test1();
  return 0;
}

