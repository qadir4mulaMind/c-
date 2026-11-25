#include<iostream>
#include<memory>

class UDT{
  public:
    // Constructor (called on creation)
    UDT(){
      std::cout << "UDT Created" << std::endl;
    }

    // Destructor (Called on destruction)
    ~UDT(){
      std::cout << "UDT Destructed" << std::endl;
    }
};

int main(){
  {
  // Creating our shared pointer  
  std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();

  {
    
    std::weak_ptr<UDT> ptr2 = ptr1;

    std::cout << "Use count: " << ptr2.use_count() << std::endl;
  }// then ptr2 is freed 

  std::cout << "use count: " << ptr1.use_count() << std::endl;
} 

  std::cout << "WE shold the behiviour of destructor" << std::endl;
  return 0;
}

