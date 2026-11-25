#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include<ctime>

void test0(){
  std::pair<int, int> s1 = std::minmax(7, 2);
  std::pair<int, int> s2 = std::minmax(2, 7);

  std::cout << s1.first << "," << s1.second << std::endl;
  std::cout << s2.first << "," << s2.second << std::endl;
}

void test1(){
  std::vector<int> v1{1, 3, 5, 7, 9, 11, 13, 15, 17};
  std::srand(std::time(0));

  const auto [lower_bound, upper_bound] = std::minmax(std::rand() % v1.size(), std::rand() % v1.size());
  std::cout << lower_bound << "," << upper_bound << std::endl;
}

int main(){
  test0();
  test1();
  return 0;
}
