#include<iostream>

struct Point3D{

  explicit Point3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z), w(0.1f){
  }

  void changeW(float newW) const{
    w = newW;
  }

  float x, y, z;
  mutable float w;
};


int main(){

  Point3D p{1.0f, 2.0f, 3.0f};
  p.changeW(5.0);

  std::cout << p.x << "\n" << p.y << "\n" << p.z << "\n" << p.w << "\n";

  return 0;
}

