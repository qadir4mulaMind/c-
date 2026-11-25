#include<iostream>
#include<iterator>
#include<vector>
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

  auto x = std::find(v1.begin(), v1.end(), 5);
  v1.erase(x);

  print(v1);

  std::erase(v1, 6);

  print(v1);

}

int main(){
  test0();
  return 0;
}
