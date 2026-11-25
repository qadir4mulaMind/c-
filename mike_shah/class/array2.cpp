#include<iostream>
#include "array2.hpp"

Array::Array(){
  std::cout << "Constructor" << std::endl;
  for(int i = 0; i < 10; i++){
    data.push_back(i);
  }
}

Array::~Array(){
  //delete[] data;
}

Array::Array(const Array& rhs){
  for(int i = 0; i < 10; i++){
    data.push_back(rhs.data[i]);
  }
}

Array& Array::operator = (const Array& rhs){
  std::cout << "Copy Assignment operator" << std::endl;
  if(&rhs == this){
    return *this;
  }
  data.clear();
  for(int i = 0; i < 10; i++){
    data.push_back(rhs.data[i]);
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

