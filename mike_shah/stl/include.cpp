#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

void test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6};
  std::vector<int> v2{21, 2, 3};

  auto result = std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());

  std::cout << std::boolalpha;
  std::cout << result << std::endl;
}

int main(){
  test0();
  return 0;
}
