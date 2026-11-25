#include<iostream>
#include<vector>
#include<algorithm>

int main(){
  std::vector<int> v{1, 5, 2, 7, 3, 0};
  std::vector<int> s{2, 7, 3};

  auto result = std::search(v.begin(), v.end(), s.begin(), s.end());

  if (result != v.end()) {
    std::cout << *result << std::endl;
  } else {
    std::cout << "Not found" << std::endl;
  }

  return 0;
}
