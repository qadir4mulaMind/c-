#include<iostream>
#include<string>

class UDT{
  public:
    explicit UDT(int);

  private:
    int m_var;
};

UDT::UDT(int i){
  m_var = i;

  std::cout << "m_var " << m_var << std::endl;
}

int main(){

  UDT u1{100};

  return 0;
}

