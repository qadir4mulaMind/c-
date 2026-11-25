#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>
#include<algorithm>

void test0(){
  std::vector<int> v1{1, 2, 3,4 ,5};
  std::vector<int> result(v1.size());

  std::partial_sum(v1.begin(), v1.end(), result.begin());

  std::for_each(result.begin(), result.end(), [](const auto& ele){
      std::cout << ele << ",";
      });
  std::cout << std::endl;
}

int main(){
  test0();
  return 0;
}
