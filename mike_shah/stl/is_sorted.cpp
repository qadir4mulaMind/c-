#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

void test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> v2{1, 2, 3, 4, 5, 6, 7, -1};

  std::cout << std::is_sorted(v1.begin(), v1.end()) << std::endl;
  std::cout << std::is_sorted(v2.begin(), v2.end()) << std::endl;
}

void test1(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, -1};

  auto it = std::is_sorted_until(v1.begin(), v1.end());
  std::cout << *it << std::endl;
}

int main(){
  test0();
  test1();
  return 0;
}

