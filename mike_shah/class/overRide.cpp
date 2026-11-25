#include<iostream>

class Base{
  public:
    Base(){
      std::cout << "Base constructor" << std::endl;
    }

    ~Base(){
      std::cout << "Base Destructor" << std::endl;
    }

   virtual void mfun(){
      std::cout << "mfun(Base)" << std::endl;
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

    void mfun() override{
      std::cout << "mfun(Derived)" << std::endl;
    }
};
/*
int main(){
  Base* b1 = new Derived; 
  b1->mfun();
  delete b1;

  return 0;
} 
Base constructor
Derived Constructor
mfun(Derived)
Base Destructor*/

/*int main(){
  Base* b1 = new Base();
  b1->mfun();
  delete b1;
  return 0;
}
Base constructor
mfun(Base)
Base Destructor*/

int main(){
  Derived d;
  return 0;
};
