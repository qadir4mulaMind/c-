#include<iostream>

float lerp(float a, float b, float t){
  return a + t * (b - a);
}

int main(){
  std::cout << lerp(10.0f, 110.0f, 0.5f) << std::endl;
  std::cout << lerp(0.0f, 1.0f, 1.1f) << std::endl;

  std::cout << lerp(10.0f, 110.0f, 0.5f) << std::endl;
  std::cout << lerp(0.0f, 1.0f, 1.1f) << std::endl;

  return 0;
}
