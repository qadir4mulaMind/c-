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
  std::vector<int> v1{1, 3, 5, 5, 5, 5, 5, 7, 9};
  std::vector<int> v2{2, 4, 6, 5, 5};

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::list<int> out;

  std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(out));

  print(out);
}

void test1(){
  std::vector<int> v1{1, 3, 5, 5, 5, 5, 5, 7, 9};
  std::vector<int> v2{2, 4, 6, 5, 5};

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::list<int> out;

  std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(out));

  print(out);
}


int main(){
  test0();
  test1();
  return 0;
}
