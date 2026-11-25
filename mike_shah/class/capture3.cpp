#include<iostream>
#include<vector>
#include<algorithm>

int global = 1;

int main(){
  
  std::vector<int> v{1, 2, 3, 4, 5};

  int lst1 = -1;
  int lst2 = -2;

  auto print_v = [&](int n){
    global = 10;
    std::cout << lst1 << "\n";
    std::cout << n << ",";
  };

  std::for_each(begin(v), end(v), print_v);

  std::cout << "\n" << global << std::endl;
  return 0;
}

