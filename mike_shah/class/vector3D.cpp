#include <iostream>
#include "vector3D.hpp"

// Default Constructor (Initializes to 0.0)
Vector3D::Vector3D() {
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
}

// Parameterized Constructor
Vector3D::Vector3D(float x, float y, float z) {
  setParameter(x, y, z);
}

// Setter function fixed (using 'this->' to avoid name hiding confusion)
void Vector3D::setParameter(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

// Print function fixed (printing correct x, y, and z variables)
void Vector3D::printVector(const Vector3D& v) {
  std::cout << "x: " << v.x << std::endl;
  std::cout << "y: " << v.y << std::endl;
  std::cout << "z: " << v.z << std::endl;
}

// Operator+ fixed syntax and type matching
Vector3D Vector3D::operator+(const Vector3D& rhs) {
  Vector3D result;
  result.x = x + rhs.x;
  result.y = y + rhs.y;
  result.z = z + rhs.z;
  return result;
}

// Operator++ fixed syntax and type matching
Vector3D Vector3D::operator++(Vector3D& v){
  v.x = x + 1;
  v.y = y + 1;
  v.z = z + 1;

  return this;
}
