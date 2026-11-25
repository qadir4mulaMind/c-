#include<iostream>
#include<vector> 
#include<list>
#include<iterator>
#include<algorithm>

auto print = [](const auto& c){
  for(const auto& ele : c){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1};

  std::list<int> out;

  std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(out));

  print(out);
}

void test1(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6};
  std::vector<int> v2{6, 7};

  std::list<int> out;

  std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(out));

  print(out);
}

int main(){
  test0();
  test1();
  return 0;
}
