#include<iostream>
#include<span>
#include<array>

void print_array(std::span<int> param){
  if(param.extent == std::dynamic_extent){
    std::cout << "dynamic " << std::endl;
  }else{
    std::cout << "static " << std::endl;
  }

  for(auto& x : param){
    std::cout << x << std::endl;
  }
}

int main(){

  std::array<int, 5> arr = {1, 2, 3, 4, 5};

  print_array(arr);

  std::span my_span(arr);

  std::cout << std::endl;

  std::cout << my_span.extent << std::endl;

  std::cout << std::endl;

  print_array(my_span);

  print_array(std::span(my_span.begin(), 3));

  return 0;
}
