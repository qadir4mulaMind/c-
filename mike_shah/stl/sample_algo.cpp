#include<iostream>
#include<iterator>
#include<vector>
#include<random>
#include<algorithm>

auto print = [](const std::vector<int>& v1){
  for(const auto& ele : v1){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
};

void test0(){
  std::vector<int> ai_bots{1, 3, 7, 6, -2};
  std::vector<int> out;

  std::sample(begin(ai_bots), begin(ai_bots) + 3, std::back_inserter(out), 2, std::mt19937{std::random_device{}()});

  print(out);
}

int main(){
  test0();
  return 0;
}
