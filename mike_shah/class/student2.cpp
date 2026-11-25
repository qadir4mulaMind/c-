#include "student2.hpp"
#include <iostream>
// Action -Constructor

Student::Student(std::string name){
  m_name = name;
  std::cout << "Constructor: " << m_name << std::endl;
}

Student::~Student(){
  std::cout << "Destructor: " << m_name << std::endl;
}

