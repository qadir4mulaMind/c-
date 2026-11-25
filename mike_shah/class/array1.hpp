#ifndef ARRAY1_HPP
#define ARRAY1_HPP

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
      int* data;
};
#endif
