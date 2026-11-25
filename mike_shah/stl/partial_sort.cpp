#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

auto print = [](const std::vector<int>& v1, const char* c){
  std::cout << c << ": ";
  for(const auto & ele : v1){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector<int> v1{5, 1, 3, 9, 7, 2, 4, 6, 8};
  print(v1, "Before");
  auto m = v1.begin() + v1.size() / 2;
  std::nth_element(v1.begin(), m, v1.end());
  print(v1, "After");
}

void test1(){
  std::vector<int> v1{5, 1, 3, 9, 7, 2, 4, 6, 8};
  print(v1, "Before");
  auto m = v1.begin() + v1.size() / 2;
  std::partial_sort(v1.begin(), m, v1.end(), std::greater<int>());
  print(v1, "After");
}


int main(){
  test0();
  test1();
  return 0;
}

