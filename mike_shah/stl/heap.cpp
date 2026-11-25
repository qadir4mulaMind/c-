#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<list>

auto print = [](const auto& c){
  for(const auto& ele : c){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector<int> v{1, 3, 8, 2, 9};
  print(v);

  std::make_heap(begin(v), end(v));
  print(v);
}

void test1(){
  std::vector<int> v{1, 3, 8, 2, 9};
  print(v);

  while(!v.empty()){
    std::cout << v.front() << " ";
    std::pop_heap(v.begin(), v.end());
    v.pop_back();
  }
  std::cout << std::endl;

  print(v);
}

void test2(){
  std::vector<int> v{1, 3, 8, 2, 9};
  print(v);
  std::make_heap(v.begin(), v.end());
  std::sort_heap(v.begin(), v.end());

  print(v);
}



int main(){
  test0();
  test1();
  test2();
  return 0;
}
