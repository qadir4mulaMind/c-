#include<iostream>
#include<algorithm>
#include<vector>

void test0(){
  std::vector<int> v{1, 2, 3, 4, 4, 4, 4, 5, 6};

  auto result = std::count(v.cbegin(), v.cend(), 4);

  std::cout << "count is: " << result << std::endl;
}
void test1(){
  std::vector<int> v{1, 2, 3, 4, 5, 6};

  auto result = std::count_if(v.cbegin(), v.cend(), [](int ele){
      return ele >= 4;
      });
   
  std::cout << "count is: " << result << std::endl;
}

int main(){
  test0();
  test1();
  return 0;
}

