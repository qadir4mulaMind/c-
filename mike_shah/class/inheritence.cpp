#include<iostream>

class Dog{// base
  public:
    Dog(){
    }

    void bark(){
      std::cout << "bark!" << std::endl;
    }

    void walk(){
      x += 1;
      y += 1;
    }
    
    float x, y;
};

class Golden : public Dog{
  public:
    Golden(){
      x = 0;
    }

    void r(){
      std::cout << "retriving a stick\n" << std::endl;
      x++;
    }

    float m;
};

class Husky : public Dog{
};


int main(){
  
  Dog dog;
  dog.bark();

  Golden dog1;
  dog1.walk();
  dog1.bark();
  dog1.r();

  std::cout << "sizeof(Dog): " << sizeof(Dog) << std::endl;
  std::cout << "sizeof(Golden): " << sizeof(Dog) << std::endl;

  return 0;
}
