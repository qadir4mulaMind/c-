#include<iostream>

struct API{
  API();
  ~API();

  static int MAJOR;
  static int MINOR;
};

int API::MAJOR = 7;

int main(){
 // API ins;
 // ins.MAJOR = 7;
  std::cout << "MAJOR " << API::MAJOR << std::endl;
  return 0;
}
