#pragma once
#include <cstddef>
#include <compare>
#include <iterator>

namespace mystl {

// Custom Back Inserter Adaptor
template <typename Container>
class MyBackInserter {
    Container* container;
public:
    using iterator_category = std::output_iterator_tag;
    using value_type        = void;
    using difference_type   = void;
    using pointer           = void;
    using reference         = void;

    explicit MyBackInserter(Container& c) : container(&c) {}

    MyBackInserter& operator*() { return *this; }
    MyBackInserter& operator++() { return *this; }
    MyBackInserter& operator++(int) { return *this; }

    MyBackInserter& operator=(const typename Container::value_type& value) {
        container->push_back(value);
        return *this;
    }
};

template <typename Container>
MyBackInserter<Container> my_back_inserter(Container& c) {
    return MyBackInserter<Container>(c);
}

// Custom Vector
template <typename T>
class MyVector {
public:
    // --- Normal Random Access Iterator ---
    class iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        iterator(pointer ptr = nullptr) : m_ptr(ptr) {}
        
        reference operator*() const { return *m_ptr; }
        pointer operator->() const { return m_ptr; }
        
        iterator& operator++() { ++m_ptr; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++m_ptr; return tmp; }
        iterator& operator--() { --m_ptr; return *this; }
        iterator operator--(int) { iterator tmp = *this; --m_ptr; return tmp; }
        
        iterator operator+(difference_type n) const { return iterator(m_ptr + n); }
        iterator operator-(difference_type n) const { return iterator(m_ptr - n); }
        difference_type operator-(const iterator& other) const { return m_ptr - other.m_ptr; }
        
        reference operator[](difference_type n) const { return *(m_ptr + n); }
        
        bool operator==(const iterator& other) const { return m_ptr == other.m_ptr; }
        bool operator!=(const iterator& other) const { return m_ptr != other.m_ptr; }
        auto operator<=>(const iterator& other) const { return m_ptr <=> other.m_ptr; }

    private:
        pointer m_ptr;
    };

    // --- Reverse Iterator Adaptor ---
    class reverse_iterator {
        iterator current;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        reverse_iterator(iterator it) : current(it) {}

        reference operator*() const {
            iterator tmp = current;
            return *(--tmp); 
        }
        
        reverse_iterator& operator++() { --current; return *this; }
        reverse_iterator operator++(int) { reverse_iterator tmp = *this; --current; return tmp; }
        reverse_iterator& operator--() { ++current; return *this; }
        
        bool operator==(const reverse_iterator& other) const { return current == other.current; }
        bool operator!=(const reverse_iterator& other) const { return current != other.current; }
    };

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

public:
    MyVector() : m_data(nullptr), m_size(0), m_capacity(0) {}
    
    ~MyVector() { delete[] m_data; }

    iterator begin() { return iterator(m_data); }
    iterator end() { return iterator(m_data + m_size); }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }

    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    T& operator[](size_t index) { return m_data[index]; }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            size_t new_cap = (m_capacity == 0) ? 1 : m_capacity * 2;
            T* new_data = new T[new_cap];
            for (size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_cap;
        }
        m_data[m_size++] = value;
    }
};

} // namespace mystl