#include<iostream>
#include<vector>
#include<algorithm>

int main(){
  
  std::vector<int> v{1, 2, 3, 4, 5};

  int lst1 = -1;
  int lst2 = -2;

  auto print_v = [&lst1, &lst2](int n){
    lst1 = n;
    lst2 = n;
    std::cout << n << ",";
  };

  std::for_each(begin(v), end(v), print_v);

  std::cout << "\n" << lst1 << std::endl;
  std::cout << lst2 << std::endl;
  return 0;
}

