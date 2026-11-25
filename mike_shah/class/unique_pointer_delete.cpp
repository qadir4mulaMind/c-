#include<iostream>

struct IntDeleter{
  void operator()(int* int_ptr){
    std::cout << "IntDeleter Called" << std::endl; 
    delete int_ptr;
  }
};

int main(){
  
  std::unique_ptr<int, IntDeleter> my_ptr(new int);

  return 0;
}
