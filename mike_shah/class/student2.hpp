#ifndef STUDENT2_HPP
#define STUDENT2_HPP
#include<string>

class Student{// Student our new user defined data type
  public:
    // Action constructor
    Student(std::string name);

    // Action Destructor
    ~Student();
  private:
    std::string m_name;
};
#endif

