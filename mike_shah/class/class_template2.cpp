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

    static T m_variable;

private:
    T* m_data;
};

// static member variable telling the compiler hey we exist
template<typename T, int size>
T Container<T, size>::m_variable;

int main() {
    Container<int, 10> c1;
    Container<int, 5> c2;
    Container<int, 5>::m_variable = 7;   
    std::cout << Container<int, 5>::m_variable << std::endl;
    return 0;
}
