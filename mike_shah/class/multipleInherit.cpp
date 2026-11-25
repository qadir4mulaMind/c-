#include<iostream>

struct NonCopyable{
  NonCopyable() = default;
  NonCopyable(const NonCopyable& rhs) = delete;
  NonCopyable& operator = (const NonCopyable& rhs) = delete;
};

struct Dog : public NonCopyable {
  virtual void bark(){
    std::cout << "Dog Barks\n";
  }
};

struct Golden :  public Dog{
  virtual void bark() override{
    std::cout << "Golden Bark\n";
  }
};

struct BorderCollie :  public Dog{
  virtual void bark() override{
    std::cout << "BorderCollie Bark\n" << std::endl;
  }
};

struct Coltriever : public Golden, BorderCollie{
    void bark() override{
    std::cout << "Coltriever Bark\n" << std::endl;
  }
};

int main(){
  Dog dog2;
  Dog dog3;
  dog3 = dog2;
  Dog* dog = new Dog;
  Dog* golden = new Golden;
  Dog* borderCollie = new BorderCollie;
  Coltriever* coltriever = new Coltriever;

  dog->bark();
  golden->bark();
  borderCollie->bark();
  coltriever->bark();

  return 0;
}
