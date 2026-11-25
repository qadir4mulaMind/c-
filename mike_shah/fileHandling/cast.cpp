#include<iostream>

struct Pair{ /*vector1*/
  float x, y;
};


struct Triple{ /*vector2*/
  float values[3];

  Triple(){
    std::cout << "Triple: Triple() constructor.\n";
  }

  Triple(const Pair& p){
    std::cout << "Triple: Triple(Pair) constructor.\n";
    values[0] = p.x;
    values[1] = p.y;
  }

  operator Pair() const{
    return {values[0], values[1]};
  }
};

void test0(){
  double f = 43.257;

  std::cout << "Simple cast: " <<  int(f) << std::endl;

  std::cout << "Static Cast: " << static_cast<int>(f) << std::endl;

  // std::cout << "Reinterpret Cast: " << reinterpret_cast<int>(f) << std::endl;
  std::cout << "Reinterpret Cast: " << *reinterpret_cast<int*>(&f) << std::endl;
}

void test1(){
  Pair p;
  p.x = 10.10f;
  p.y = 11.11f;

  Triple t;
  t.values[0] = 1.1f;
  t.values[1] = 2.2f;
  t.values[2] = 3.3f;

  t = p;
  Triple t2 = p;

  std::cout << ((Pair)t).x << std::endl;
}

int main(){
  test0();
  std::cout << std::endl;
  test1();
  return 0;
}
