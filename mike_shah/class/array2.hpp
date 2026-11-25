#ifndef ARRAY2_HPP
#define ARRAY2_HPP
#include<vector>

class Array{
  public:
    // Special function 
    // (1) Constructor
    Array();
    // (2) Destructor
    ~Array();
    //(3) Copy Constructor
    Array(const Array& rhs);
    // (3 or 4) assignment operator 
    Array& operator =(const Array& rhs);

    void printData();
   
    void setData(int idx, int val);

    private:
      std::vector<int> data;
};
#endif
