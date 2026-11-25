#ifndef CLASS1_HPP
#define CLASS1_HPP
class Student{ // Our user defined data type
  public:
    // Special Action
    // Action - Constructor
    std::string m_name;
    Student(){
      std::cout << "Constructor " << std::endl;
    }

    // Action -Destructor
    ~Student(){
      std::cout << "Destructor: " << m_name << std::endl;
    }

    // Hidden "field' and 'attributes'
};
#endif
