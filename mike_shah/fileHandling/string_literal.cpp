#include<iostream>
#include<string>

void test0(){
  std::string shader = " \
void main(){\n    \ 
  \n            \
}               \
   \n ";
  std::cout << shader << std::endl;

  std::string shader2(R"(
    void main(){

    })");

  std::cout << shader2 << std::endl;
}

int main(){
  test0();
  return 0;
}
