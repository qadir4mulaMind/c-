#include<iostream>

class Base{
  public:
    Base(){
      std::cout << "Base constructor" << std::endl;
      baseData = new int[10];
    }

    virtual ~Base(){
      std::cout << "Base Destructor" << std::endl;
      delete [] baseData;
    }

   virtual void mfun(){
      std::cout << "mfun(Base)" << std::endl;
    }

    int* baseData;
};

class Derived : public Base{
  public:
    Derived(){
      std::cout << "Derived Constructor" << std::endl;
      derivedData = new int[15];
    }

    ~Derived(){
      std::cout << "Derived Destructor" << std::endl;
      delete derivedData;
    }

    void mfun() override{
      std::cout << "mfun(Derived)" << std::endl;
    }
    int* derivedData;
};


int main(){
  // Create a Base* that can point to 'Base' or "Derived" anything 'is - a' .
  // we have also a vtable that is created for this object of instance of object
  Base* b1 = new Derived;
  // when we call a member function the vtable points to the coreect member function
  b1->mfun();
  delete b1;
  printf("\n"); 
  b1 = new Base;
  b1->mfun();
  delete b1;
  return 0;
};
