#include<iostream>
#include<vector>
#include<algorithm>

struct print_functor{
  int& lst;
  inline void operator()(int n){
    lst = n;
    std::cout << n << ",";
  }
};

int main(){
  
  std::vector<int> v{1, 2, 3, 4, 5};

  int lst = -1;

  auto print_v = [&lst](int n){
    lst = n;
    std::cout << n << ",";
  };

  std::for_each(begin(v), end(v), print_v);

  std::cout << "\n" << lst << std::endl;
  return 0;
}

