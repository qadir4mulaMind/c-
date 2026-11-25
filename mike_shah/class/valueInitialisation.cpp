#include<iostream>

struct Entity{
  Entity() : name{}, x{0}, y{0}, collection{nullptr}{
    init();
    // Compute some algorithm
    // Add our entity to add some data structure
  }

  Entity(std::string _name) : Entity(){ 
    name = _name;
  }

  Entity(int _x, int _y) : Entity(){
    x = _x;
    y = _y;
  }

  std::string name;
  int* collection{nullptr};
  int x{0}, y{0};

  public:
    void init(){
      // Compute some algorithm
      // add our entity to some data structure
      x = 7;
      y = 5;
      name = std::to_string(x) + std::to_string(y);
   }
};

int main(){
  Entity e{9, 46};
  std::cout << e.name << std::endl;
  std::cout << e.collection << std::endl;
  std::cout << e.x << std::endl;
  std::cout << e.y << std::endl;
  return 0;
}
