#include<iostream>

class Base{
  public:

    Base(){
      std::cout << "Base constructor" << std::endl;
    }

    ~Base(){
      std::cout << "Base destructor" << std::endl;
    }

    void memberFunction(){
      std::cout << "memberFunction(base)" << std::endl;
    }
};

class Derived : public Base{
  public:
    Derived(){
        std::cout << "Derived Constructor" << std::endl;
    }
    
    ~Derived(){
      std::cout << "Derived Destructor" << std::endl;
    }

    void memberFunction(){
      std::cout << "memberFunction(Derived)" << std::endl;
    }
};

int main(){

  Base b1;

  b1.memberFunction();

  Derived d1;
  
  d1.memberFunction();

  return 0;
}
