#include<iostream>
#include<unordered_set>

int main(){

  std::unordered_set<int> u1;
  u1.reserve(5); 

  std::cout << u1.bucket_count() << std::endl;

  std::unordered_set<int> u2{1, 2, 3, 4, 5, 6};
  
  for(const auto& x : u2){
    std::cout << x << ", ";
  }

  std::cout << std::endl;
  return 0;
}
