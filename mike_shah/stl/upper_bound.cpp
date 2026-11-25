#include<iostream>
#include<iterator>
#include<iomanip>
#include<algorithm>
#include<vector>

void test0(){
  std::vector<int> v{1, 3, 5, 7, 9, 11, 12, 13, 14};

  auto found = std::binary_search(begin(v), end(v), 7);
  std::cout << std::boolalpha;
  std::cout << "found: " << found << std::endl;
}

void test1(){
  std::vector<int> v{1, 3, 5, 5, 5, 5, 5, 7, 9, 11, 12, 13, 14};
  auto lower = std::lower_bound(v.begin(), v.end(), 5);
  auto upper = std::upper_bound(v.begin(), v.end(), 5);
std::cout << std::boolalpha;
  std::cout << *upper << std::endl;
  std::cout << *lower << std::endl;
}

int main(){
  test0();
  test1();
  return 0;
}
