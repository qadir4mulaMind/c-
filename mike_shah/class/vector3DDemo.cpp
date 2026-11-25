#include <iostream>
#include "vector3D.hpp"

int main() {
  Vector3D v1(1.0f, 2.0f, 3.0f);
  Vector3D v2(4.0f, 5.0f, 6.0f);

  std::cout << "--- Vector 1 ---" << std::endl;
  v1.printVector(v1);

  std::cout << "\n--- Vector 2 ---" << std::endl;
  v2.printVector(v2);

  // Testing the overloaded + operator
  Vector3D v3 = v1 + v2; 

  std::cout << "\n--- Result Vector (v1 + v2) ---" << std::endl;
  v3.printVector(v3);

  ++v1;

  return 0;
}

