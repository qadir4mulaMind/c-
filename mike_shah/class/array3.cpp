#include <iostream>
#include "array3.hpp"

// (1) Default Constructor - Fills 100,000 items
Array::Array() {
  std::cout << "[LOG] Default Constructor Called" << std::endl;
  for(int i = 0; i < 100000; i++) {
    data.push_back(i);
  }
}

// (2) Destructor - Trivial (Vector handles memory cleanup automatically)
Array::~Array() {
  // Left empty deliberately
}

// (3) Copy Constructor - Element-by-element deep copy
Array::Array(const Array& rhs) {
  std::cout << "[LOG] Copy Constructor Called (Massive Loop Running...)" << std::endl;
  for(size_t i = 0; i < rhs.data.size(); i++) {
    data.push_back(rhs.data[i]);
  }
}

// (4) Copy Assignment Operator
Array& Array::operator=(const Array& rhs) {
  std::cout << "[LOG] Copy Assignment Operator Called" << std::endl;
  if(&rhs == this) {
    return *this;
  }
  
  data.clear();
  for(size_t i = 0; i < rhs.data.size(); i++) {
    data.push_back(rhs.data[i]);
  }
  
  return *this; // Return reference to current object
}

void Array::printData() {
  // Printing only first 3 items to keep terminal clean
  for(size_t i = 0; i < 3; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << "... [Total size: " << data.size() << "]" << std::endl;
}

void Array::setData(int idx, int val) {
  data[idx] = val;
}

size_t Array::getSize() const {
  return data.size();
}
