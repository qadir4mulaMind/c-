#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

void test0(){
  std::vector v1{1, 3, 5, 7};
  std::vector v2{1, 7, 4, 3};

  auto predictate = [](int i){
    return i < 4;
  };

  auto v1_test = std::is_partitioned(v1.begin(), v1.end(), predictate);
  auto v2_test = std::is_partitioned(v2.begin(), v2.end(), predictate);

  std::cout.setf(std::ios_base::boolalpha);
  std::cout << v1_test << std::endl;
  std::cout << v2_test << std::endl;
}

int main(){
  test0();
  return 0;
}

