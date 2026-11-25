#include<iostream>

class Student{ // Our user defined data type
  public:
    // Special Action
    // Action  - Constructor
    Student(){
      std::cout << "Constructor" << std::endl;
    }

    // Action -Destructor
    ~Student(){
      std::cout << "Destructor" << std::endl;
    }
    
    // Hidden "field' and 'attributes'
  private:
    std::string m_name;
};

int main(){
  std::cout << "Program starts!!" << std::endl;
  Student* mike = new Student; 
  delete mike;
  std::cout << "Program ends!!" << std::endl;
  return 0;
}
