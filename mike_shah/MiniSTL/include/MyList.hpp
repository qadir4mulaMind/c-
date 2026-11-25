#pragma once
#include <cstddef>
#include <iterator>

namespace mystl {

template <typename T>
class MyList {
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* m_head;
    Node* m_tail;
    size_t m_size;

public:
    // --- Bidirectional Iterator ---
    class iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        Node* node;
        iterator(Node* n = nullptr) : node(n) {}

        reference operator*() const { return node->data; }
        pointer operator->() const { return &(node->data); }

        iterator& operator++() { node = node->next; return *this; }
        iterator operator++(int) { iterator tmp = *this; node = node->next; return tmp; }
        
        iterator& operator--() { node = node->prev; return *this; }

        bool operator==(const iterator& other) const { return node == other.node; }
        bool operator!=(const iterator& other) const { return node != other.node; }
    };

    MyList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    
    ~MyList() {
        Node* current = m_head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value);
        if (!m_head) {
            m_head = m_tail = new_node;
        } else {
            m_tail->next = new_node;
            new_node->prev = m_tail;
            m_tail = new_node;
        }
        m_size++;
    }

    iterator begin() { return iterator(m_head); }
    iterator end() { return iterator(nullptr); }
    size_t size() const { return m_size; }
};

} // namespace mystl