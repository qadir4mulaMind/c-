#include<iostream>

void print(const int arr[]){
  std::cout << "sizeof(arr): " << sizeof(arr) << std::endl;
}

int main(){
  int array[] = {1, 2, 3, 4, 5};
  print(array);
  return 0;
}
