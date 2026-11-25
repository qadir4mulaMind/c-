#include<iostream>

template<typename T>
T sum(T args){
  return args;
}

template<typename T, typename... Args>
T sum(T start,Args... args){
  return start + sum(args...);
}


int main(){

  std::cout << sum<double, double>(1, 2.2f, 3.4f, 4, 5) << std::endl;

  return 0;
}
