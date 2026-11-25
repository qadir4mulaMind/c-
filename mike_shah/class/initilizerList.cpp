#include<iostream>

struct UDT{
  UDT(int a, int b, int c){
    std::cout << "Constructor with 3 pram\n";
  }
  ;
  UDT(std::initializer_list<int> data) : m_data(data){
    std::cout << "initializer_list constructor \n";
    m_data;
  }

  ~UDT(){}
  void printData(){
      for(auto& e : m_data){
        std::cout << e << " , ";
      }
      std::cout << std:: endl;
  }

  private:
    std::initializer_list<int> m_data;
};

int main(){
  UDT u{1, 2, 3};
  u.printData();

  UDT u2{1.1, 2.2, 3.3};

  return 0;
}
