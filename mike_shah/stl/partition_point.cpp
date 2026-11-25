#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

void test0(){
  std::vector v1{1, 4, 7, 2, -5, 8, 5, 3, 10, 11, 12};
  auto p = [](int a){
    return a < 6;
  };

  if(!std::is_partitioned(v1.begin(), v1.end(), p)){
      std::partition(v1.begin(), v1.end(), p);
  }

  for(const auto& ele : v1){
    std::cout << ele << " ";
  }
  std::cout << std::endl;

  auto point = std::partition_point(v1.begin(), v1.end(), p);

  auto d = std::distance(v1.begin(), point);

  std::cout << "d: " << d << std::endl;
  std::cout << "Partition Point: " << *point << std::endl;
  std::cout << "v1.size(): " << v1.size() << std::endl;
  std::cout << "v1.size()/2: " << v1.size() / 2 << std::endl;
}

void test1(){
  std::vector v1{1, 4, 7, 2, -5, 8, 5, 3, 10, 11, 12};
  auto p = [](int a){
    return a < 6;
  };

  std::vector<int> left;
  std::vector<int> right;

  std::partition_copy(v1.begin(), v1.end(), std::back_inserter(left), std::back_inserter(right), p);

  for(const auto& ele : left){
    std::cout << ele << " ";
  }
  std::cout << std::endl;

  for(const auto& ele : right){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}


int main(){
  test0();
  test1();
  return 0;
}
