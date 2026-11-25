#include<iostream>
#include<vector>
#include<algorithm>

struct Value{
  int m_result{0};

  int operator()(int res){
    m_result = res;
    return res;
  }
};

int main(){
  Value v;
  v(42);
  std::cout << v.m_result << std::endl;
  return 0;
}
