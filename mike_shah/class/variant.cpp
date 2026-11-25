#include<iostream>
#include<variant>

union U{
  int i;
  short s;
  float f;
};

int main(){
  std::variant<int, float> data;
  U u1;
  data = 7.0f;
  std::cout << std::get<float>(data) << std::endl;
  std::cout << sizeof(u1) << std::endl;
  std::cout << sizeof(data) << std::endl;

  if(auto attempt = std::get_if<float>(&data)){
    std::cout << "we found a float" << std::endl;
  }

  std::cout << get<float>(data) << std::endl;

  std::cout << data.index() << std::endl;
  return 0;
}

