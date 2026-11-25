#include <iostream>

class Vector3D {
private:
    float x;
    float y;
    float z;

public:
    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

   
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
};


std::ostream& operator<<(std::ostream& output, const Vector3D& v) {
    // Direct v.x nahi likh sakte, isliye v.getX() use kiya
    output << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return output;
}

int main() {
    Vector3D v1(1.5f, 2.5f, 3.5f);
    
    // Direct printing matches your exact output syntax requirements
    std::cout << "Vector v1: " << v1 << std::endl; 
    
    return 0;
}
