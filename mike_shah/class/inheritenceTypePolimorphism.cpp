#include<iostream>

class Base{
  public:
    Base(){
      std::cout << "Base constructor" << std::endl;
    }

    ~Base(){
      std::cout << "Base Destrcutor" << std::endl;
    }
    
    void memberFunction(){
      std::cout << "memberFunction(Base)" << std::endl;
    }
};

class Derived : public Base{
  public:
    Derived(){
      std::cout << "Derived constructor " << std::endl;
    }

    ~Derived(){
      std::cout << "Derived Destructor" << std::endl;
    }

    void memeberFunction(){
      std::cout << "memberFunction" << std::endl;
    }
};

int main(){

  Base* b1 = new Derived;
   
  b1->memberFunction();

  delete b1;
}
