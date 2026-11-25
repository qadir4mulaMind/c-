#include<iostream>
#include "array1.hpp"

Array::Array(){
  std::cout << "Constructor" << std::endl;
  data = new int[10];
  for(int i = 0; i < 10; i++){
    data[i] = i * i;
  }
}

Array::~Array(){
  delete[] data;
}

Array::Array(const Array& rhs){
  data = new int[10];
  for(int i = 0; i < 10; i++){
    data[i] = rhs.data[i];
  }
}

Array& Array::operator = (const Array& rhs){
  std::cout << "Copy Assignment operator" << std::endl;
  if(&rhs == this){
    return *this;
  }
}

void Array::printData(){
  for(int i = 0; i < 10; i++){
    std::cout << data[i] << std::endl;
  }
}

void Array::setData(int idx, int val){
  data[idx] = val;
}

