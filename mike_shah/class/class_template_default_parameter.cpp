#include<iostream>

template<typename T = int, int size = 10>
class Conatiner{
  public:
    Conatiner(){
      m_data = new T[size];
      std::cout << size << std::endl;
    }

    ~Conatiner(){
      delete[] m_data;
    }

  private:
    T* m_data;
};

int main(){
  Conatiner<int, 5> c1;
  Conatiner c2;
  return 0;
}

