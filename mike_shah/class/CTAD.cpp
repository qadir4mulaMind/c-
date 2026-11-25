#include<iostream>
#include<vector>
template<typename first, typename second>
struct Entry{
  Entry(first key, second val){
    m_key = key;
    m_val = val;
  }
  first m_key;
  second m_val;
};

int main(){
  // class template argument deduction(CDAT)
  Entry entry(5, 100.1f);
  std::cout <<entry.m_key << std::endl;
  std::cout <<entry.m_val << std::endl;
  std::vector v1{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
  return 0;
}

