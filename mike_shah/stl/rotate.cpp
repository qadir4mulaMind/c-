#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

auto print = [](const std::vector<int>& v1){
  for(const auto& ele : v1){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  print(v1);

  std::rotate(v1.begin(), v1.begin() + 2, v1.end());

  print(v1);
}

void test1(){
  std::vector<int> v1{8, 5, 9, 4, 0, 6, 1, 2, 3};

  print(v1);

  for(auto i = v1.begin(); i != v1.end(); i++){
    std::rotate(std::upper_bound(v1.begin(), i, *i), i, i + 1);
  }

  print(v1);
}

 void test2(){
   std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
   print(v1);
   std::rotate(v1.rbegin(), v1.rbegin() + 2, v1.rend());
   print(v1);
 }

int main(){
  test0();
  test1();
  test2();
  return 0;
}
