#include<iostream>
#include<vector>
#include<algorithm>

void test0(){
  std::vector<int> v{1, 2, 3, 4, 5};
  bool result = std::all_of(v.cbegin(), v.cend(), [](int i){
      return i > 0;
      });
  std::cout << "all_of > 0: " << result << std::endl;
}

void test1(){
  std::vector<int> v{-1, -3, 5, 6};
  bool result = std::any_of(v.cbegin(), v.cend(), [](int i){
      return i > 0;
      });

  std::cout << "any_of > 0: " << result << std::endl;
}

void test2(){
  std::vector<int> v{-1, 2, -3, -4, -5};
  bool result = std::none_of(v.cbegin(), v.cend(), [](int i){
      return i > 0;
      });

  std::cout << "none_of > 0: " << result << std::endl;
}

void test3(){
  std::vector<int> v{1, 2, 3, 4, -5};

  bool result = std::any_of(v.cbegin(), v.cend(), [](int i){
      return i > 0;
      });

  std::cout << "any_of > 0: " << result << std::endl;
}

int main(){
  test0();
  test1();
  test2();
  test3();
  return 0;
}

