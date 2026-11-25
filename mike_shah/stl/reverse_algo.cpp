#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

auto print = [](const std::vector<int>& v){
  for(const auto& ele : v){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
}
;

void test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};

  print(v1);

  std::cout << std::endl;
  std::cout << "=============================" << std::endl;

  std::reverse(begin(v1), end(v1));
  print(v1);
  std::cout << std::endl;
}

void test1(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};

  print(v1);

  std::cout << std::endl;
  std::cout << "=============================" << std::endl;
  std::vector<int> v2(v1.size());
  std::reverse_copy(begin(v1), end(v1), begin(v2));
    
  print(v2);
}


int main(){
  test0();
  test1();
  return 0;
}
