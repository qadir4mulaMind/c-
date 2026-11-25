#include<iostream>

struct Point2D{
  int x, y;
};

class Character{
  public:
    Character(Point2D& ref) : ref_home(ref){
      ref_home = ref;
    }
    ~Character(){}
  private:
    Point2D m_position;
    Point2D m_direction;
    Point2D& ref_home;
};

Point2D p;

void foo(){
  Character mike(p);
}

int main(){
  foo();
  return 0;
}
