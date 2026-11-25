#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

class Vector3D {
  private:
    float x;
    float y;
    float z;

  public:
    // (1) Default Constructor
    Vector3D();
    
    // (2) Parameterized Constructor
    Vector3D(float x, float y, float z);

    // Setters & Utilities
    void setParameter(float x, float y, float z);
    void printVector(const Vector3D& v);

    // Operator Overloading
    Vector3D operator+(const Vector3D& rhs);
    Vector3D operator++(Vector3D& v);
};

#endif

