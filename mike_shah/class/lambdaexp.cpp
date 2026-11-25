#include<iostream>
#include<vector>
#include<algorithm>

struct print_functor{
  void operator()(int n){
    std::cout << n << ",";
  }
};

int main(){

  std::vector<int> v{1, 2, 3, 4, 5, 6};

  auto print_v = [](int n){
    std::cout << n << ",";
  };

  std::for_each(begin(v), end(v), print_v);

  std::cout << std::endl;
  
  std::for_each(begin(v), end(v), print_functor ());

  std::cout << std::endl;  
  return 0;
}
