#include <iostream>

template<typename T, int size>
class Container {
public:

    Container() { 
        m_data = new T[size]; 
    }
    
    ~Container() { 
        delete[] m_data; 
    }


    Container(const Container&) = delete;
    Container& operator=(const Container&) = delete;

private:
    T* m_data;
};

int main() {
    Container<int, 10> c1;
    Container<double, 10> c2;
    Container<float, 10> c3;     
    return 0;
}

