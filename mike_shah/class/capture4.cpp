#include<iostream>

struct MyStruct{
  void fun(){
    auto f = [*this](){
      //counter++;
      std::cout << "counter inside labmda: " << counter << std::endl;
    };
    f();
    std::cout << "counter: " << counter << std::endl;
  }
  int counter{0};
};

int main(){
  MyStruct ins;
  ins.fun();
  ins.fun();
  ins.fun();
  return 0;
}
