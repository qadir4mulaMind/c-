#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

auto print = [](const std::vector<int>& v1, const char* c){
  std::cout << c << ": ";
  for(const auto& ele : v1){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

void check_sort(std::vector<int>& v){
  if(!std::is_sorted(v.begin(), v.end())){
    std::sort(begin(v), end(v));
  }
}


void test0(){
  std::vector<int> v1{1, 3, 5, 7, -5};
  std::vector<int> v2{2, 4, 6, -8};
  std::vector<int> result;

  print(v1, "v1 before sort");
  print(v2, "v2 before sort");

  check_sort(v1);
  check_sort(v2);

  std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));

  print(v1, "v1 after sort");
  print(v2, "v2 after sort");
  print(result, "after merge");
}

void test1(){
  std::vector<int> v{5, 7, 2, 6, 9, 8};
  print(v, "before sort");

  auto m = v.size() / 2;

  std::partial_sort(begin(v), begin(v) + m, end(v));
  std::partial_sort(begin(v) + m, end(v), end(v));

  print(v, "after sort");

}


int main(){
  test0();
  test1();
  return 0;
}
  



