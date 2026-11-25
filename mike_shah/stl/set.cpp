#include<iostream>
#include<set>

int main(){

  std::set<int> s1 {1, 2, 3, 4, 5, 6};
  s1.insert(-4);

  for(const auto& x : s1){
    std::cout << x << std::endl;
  }

  std::cout << "\ns1 count: " << s1.count(4) << std::endl;

  std::cout << "\ns1 Contain: " << s1.contains(4) << std::endl;

  auto found = s1.find(3);

  if(found != s1.end()){
    std::cout << "\nElement found " << std::endl;
    s1.erase(found);
  }

  std::cout << std::endl;

  for(const auto& x : s1){
    std::cout << x << std::endl;
  }
  std::cout << std::endl;

  std::set<int> s2{2, 4, 6, 8, 10, 12};
  
  auto lower = s2.lower_bound(4);
  auto upper = s2.upper_bound(10);

  for(auto it = lower; it != upper; ++it){
    std::cout << *it << ", ";
  }
  
  std::cout << std::endl;

  s2.erase(lower, upper);

  std::cout << std::endl;

  for(auto& it : s2){
    std::cout << it << ", ";
  }

  std::cout << std::endl;

  s1.merge(s2);

  for(auto& x : s1){
    std::cout << x << ", ";
  }

  std::cout << std::endl;

  for(auto& x : s2){
    std::cout << x << ", ";
  }

  std::cout << std::endl;
  return 0;
}
