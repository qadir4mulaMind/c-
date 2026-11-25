#include<iostream>
#include<random>
#include<vector>
#include<iterator>
#include<algorithm>

auto print = [](const std::vector<int>& v1){
  for(const auto& ele : v1){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

auto test0(){
  std::vector<int> v1{1, 2, 3, 4, 5, 6};

  print(v1);

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(v1.begin(), v1.end(), g);
  print(v1);

}

int main(){
  test0();
  return 0;
}
