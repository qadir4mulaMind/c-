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
  
  
  std::unique_ptr<UDT>mike = std::unique_ptr<UDT>(new UDT);
  std::unique_ptr<UDT> joe = std::move(mike);

  return 0;
}
