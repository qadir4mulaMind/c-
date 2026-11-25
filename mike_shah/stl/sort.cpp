#include<iostream> 
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
template<class T>
using dType = std::vector<T>;

void test0(){
  dType<int> c{1, 7, 5, 2, -7, 4, -100, 500};
  std::sort(c.begin(), c.end(), std::greater<int>());

  for(const auto& ele : c){
    std::cout << ele << " ";
  }

  std::cout << std::endl;
}

int main(){
  test0();
  return 0;
}
