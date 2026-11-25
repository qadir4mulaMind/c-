#ifndef ARRAY3_HPP
#define ARRAY3_HPP
#include <vector>

class Array {
  public:
    // (1) Default Constructor
    Array();
    
    // (2) Destructor (Trivial)
    ~Array();
    
    // (3) Copy Constructor
    Array(const Array& rhs);
    
    // (4) Copy Assignment Operator
    Array& operator=(const Array& rhs);

    void printData();
    void setData(int idx, int val);
    size_t getSize() const; // Helper to get vector size safely

  private:
    std::vector<int> data;
};
#endif
