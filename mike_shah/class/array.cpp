#include<iostream>

class Array{
  public:
    Array(){
      std::cout << "Constructor"  << std::endl;
      data = new int[10];
      for(int i = 0; i < 10; i++){
        data[i] = i * i;
      }
    }

    ~Array(){
      delete[] data;
    }

    
    Array(const Array& rhs){
      std::cout << "Copy constructor" << std::endl;
      data = new int[10];
      for(int i = 0; i < 10; i++){
        data[i] = rhs.data[i]; 
      }
    }

    // 2. Fixed Copy Assignment operator
    Array& operator = (const Array& rhs){
      std::cout << "Copy assignment operator" << std::endl;
      
      if (this == &rhs) { // Guard against self-assignment (e.g., myArr = myArr)
        return *this;
      }
      
      delete[] data; // Clean up the old array memory first!
      
      data = new int[10]; // Allocate new memory slot
      for(int i = 0; i < 10; i++){
        data[i] = rhs.data[i]; // Copy elements over
      }
      
      return *this; // Return pointer to the current object
    }

    void printData(){
      for(int i = 0 ; i < 10; ++i){
        std::cout << data[i] << std::endl;
      }
    }

    void setData(int idx, int val){
      data[idx] = val;
    }

  private:
    int* data;
};

int main(){
  Array myArr;
  myArr.setData(0, 100000);
  myArr.setData(1, 77);
  myArr.setData(2, 9999);

  Array myArr2 = myArr;

  myArr.printData();
  myArr2.printData();
  return 0;
}
