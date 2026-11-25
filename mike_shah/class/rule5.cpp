#include<iostream>
#include "rule5.hpp"
#include<string>

// Constructor
IntArray::IntArray(std::string name) : m_name(name), m_data(new int[10]){
  std::cout << m_name << " was constructed " << std::endl;
}

// Destructor
IntArray::~IntArray(){
  std::cout << m_name << " was destructed" << std::endl;
  delete[] m_data;
}

//copy Constructor Policy
IntArray::IntArray(const IntArray& rhs){
  m_name = rhs.m_name + "(copy)";
  std::cout << "was copy construdcted from " << rhs.m_name << std::endl;
  m_data = new int[10];
  for(int i = 0; i < 10; i++){
    m_data[i] = rhs.m_data[i];;
  }
}

// copy assignment operator policy
IntArray& IntArray::operator = (const IntArray& rhs){
  if(this != &rhs){
    delete[] m_data;
    m_name = rhs.m_name + "(copy)";
    std::cout << "was copy assigned from" << rhs.m_name << std::endl;
    for(int i = 0; i < 10; i++){
      m_data[i] = rhs.m_data[i];
    }
  }
  return *this;
}

