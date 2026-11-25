#include<iostream>

struct Base{

  int base{1};

  Base() : base{11}{
  }

  virtual void Do(){
    std::cout << "Base::Do\t" << base << std::endl;
  }
};

struct Derived: Base{

  int derived{2};
  
  Derived() : derived{22}{
  }
  
  void Do() override {
    std::cout << "Derived Do\t" << derived << std::endl;
  }
};


int main(){
  int x = 10;
  int* p = &x;
  std::cout << (long)p << std::endl;

  float f{3.114159f};
  int i = static_cast<int>(f);
  std::cout << i << std::endl;

  Derived* d = new Derived();
  Base* b = new Base();

  d->Do();
  b->Do();

  (static_cast<Base*>(d))->Do();

  (static_cast<Derived*>(b))->Do();

  return 0;
}
