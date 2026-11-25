#include<iostream>

class Person{
  public:
    Person(int age) : age(age){
    }

    int getAge() const{
      return age;
    }

    Person* getThisAddress(){
      return this;
    }
  
  private:
    int age;
};


int main(){
  Person p1(400);

  std::cout << p1.getThisAddress()<< std::endl;
  std::cout << &p1 << std::endl;
  return 0;
}
