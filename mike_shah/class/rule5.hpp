#ifndef RULE5_HPP
#define RULE5_HPP

class IntArray{
  public:
    // The big three
    // (1) Constructor
    IntArray(std::string name);
    // (2) Destructor
    ~IntArray();
    // copy assignment operator policy
    IntArray(const IntArray& rhs);
    IntArray& operator = (const IntArray& rhs);
    // the other  two (int total  making the 'The Big 5')
    // move constructor policy
    // IntArray(IntArray&& source);
    // move assignment policy
    // IntArray& operator = (IntArray&& source);
  private:
    std::string m_name;
    int* m_data;
};
#endif
