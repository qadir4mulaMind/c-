#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
std::vector<T> cleanUp(const std::vector<T>& data){
  std::vector<T> result;
  result.reserve(data.size());
  
  for(size_t i = 0; i < data.size(); i++){
    result.push_back(std::clamp(data[i], 0, 255));
  }
  
  return result;
}

void test0(){
  int value = 256;

  std::cout << "value before: " << value << std::endl;
  value = std::clamp(value, 0, 255);
  std::cout << "value after: " << value << std::endl;

  std::vector v = {0, 412, 244, 96, -5, 97};
  auto cleaned = cleanUp(v);

  for(const auto& ele : cleaned){
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}

int main(){
  test0();
  return 0;
}

