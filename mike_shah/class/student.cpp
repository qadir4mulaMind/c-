#include "student.hpp"
#include <iostream>
// Action -Constructor

Student::Student(){
  std::cout << "Constructor " << std::endl;
}

Student::~Student(){
  std::cout << "Destructor: " << m_name << std::endl;
}
