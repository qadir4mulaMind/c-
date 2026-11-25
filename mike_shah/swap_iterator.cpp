#include<iostream>
#include<vector>

auto print = [](const std::vector<int>& v){
  for(const auto e : v){
    std::cout << e << " ";
  }
  std::cout << std::endl;
};

void test0(){
  std::vector v1 = {1, 3, 5, 7, 9};
  std::vector v2 = {2, 4, 6, 8, 10};
  
  print(v1);
  print(v2);

  std::swap(v1, v2);

  std::cout << "=====================================\n";

  print(v1);
  print(v2);

  auto x = v1.begin() + 1;
  auto y = v2.begin() + 1;

  std::cout << "=====================================\n";

  std::iter_swap(x, y);

  print(v1);
  print(v2);
}

int main(){
  test0();
  return 0;
}
    
