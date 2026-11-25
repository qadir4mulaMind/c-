#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

struct Monstar{
  int power, strength;
};

std::ostream& operator<<(std::ostream & os, const Monstar& m){
  return os << "Monstar: " << m.power << "," << m.strength;
}

bool cmp(const Monstar& a, const Monstar& b){
  int valueA = a.power * a.strength;
  int valueB = b.power * b.strength;
  return valueA < valueB;
}

void test0(){
  std::vector<int> v{9, 4, 2, 5, 1, 0, 8, 3};
  auto minval = std::min_element(v.begin(), v.end());
  auto maxval = std::max_element(v.begin(), v.end());
  std::cout << *minval << std::endl;
  std::cout << *maxval << std::endl;
}

void test1(){
  std::vector<Monstar> v{{7, 2}, {5, 7}, {10, 11}};
  auto minval = std::min_element(v.begin(), v.end(), cmp);
  auto maxval = std::max_element(v.begin(), v.end(), cmp);
  std::cout << *minval << std::endl;
  std::cout << *maxval << std::endl;
}


int main(){
  test0();
  test1();
  return 0;
}
