#include<iostream>
#include<memory>
#include<cstdlib>

int main(){
  int* arr =  new int[100];

  for(int i = 0; i < 100; ++i){
    arr[i] = i;
  }

  int* ptr = arr;

  // output value pointed to by ptr
  std::cout << "*ptr " << *ptr << std::endl;
   delete[] arr;
   // later in my program 
   float* newarr = new float[100];
  // create a second pointer;
  int* ptr2 = ptr;
  
  std::cout << "*ptr2: "<< *ptr << std::endl;

  delete[] arr;
  return 0;
}
