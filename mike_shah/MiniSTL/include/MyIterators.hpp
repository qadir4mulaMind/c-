#pragma once
#include <iostream>
#include <string>
#include <cstddef>
#include <type_traits>

namespace mystl {

// 1. Move Iterator Adaptor
template <typename Iterator>
class MyMoveIterator {
    Iterator current;
public:
    using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
    using value_type        = typename std::iterator_traits<Iterator>::value_type;
    using difference_type   = typename std::iterator_traits<Iterator>::difference_type;
    using pointer           = typename std::iterator_traits<Iterator>::pointer;
    using reference         = typename std::iterator_traits<Iterator>::reference;

    MyMoveIterator(Iterator it) : current(it) {}
    
    value_type&& operator*() const { return std::move(*current); }
    
    MyMoveIterator& operator++() { ++current; return *this; }
    bool operator!=(const MyMoveIterator& other) const { return current != other.current; }
};

template <typename Iterator>
MyMoveIterator<Iterator> my_make_move_iterator(Iterator it) {
    return MyMoveIterator<Iterator>(it);
}

// 2. Output Stream Iterator
template <typename T>
class MyOstreamIterator {
    std::ostream* os;
    std::string delimiter;
public:
    using iterator_category = std::output_iterator_tag;
    using value_type        = void;
    using difference_type   = void;
    using pointer           = void;
    using reference         = void;

    MyOstreamIterator(std::ostream& stream, const std::string& delim) : os(&stream), delimiter(delim) {}

    MyOstreamIterator& operator*() { return *this; }
    MyOstreamIterator& operator++() { return *this; }
    
    MyOstreamIterator& operator=(const T& value) {
        *os << value << delimiter;
        return *this;
    }
};

// 3. Input Stream Iterator
template <typename T>
class MyIstreamIterator {
    std::istream* is;
    T value;
public:
    using iterator_category = std::input_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = T*;
    using reference         = T&;

    MyIstreamIterator() : is(nullptr) {}
    MyIstreamIterator(std::istream& stream) : is(&stream) { ++(*this); }

    const T& operator*() const { return value; }
    
    MyIstreamIterator& operator++() {
        if (is && !(*is >> value)) {
            is = nullptr;
        }
        return *this;
    }

    bool operator!=(const MyIstreamIterator& other) const { return is != other.is; }
};

// 4. Tag Dispatching
template <typename Iterator, typename Distance>
void advance_impl(Iterator& it, Distance n, std::random_access_iterator_tag) {
    std::cout << "[O(1) Jump used]\n";
    it = it + n;
}

template <typename Iterator, typename Distance>
void advance_impl(Iterator& it, Distance n, std::bidirectional_iterator_tag) {
    std::cout << "[O(N) Loop used]\n";
    while(n > 0) { ++it; --n; }
    while(n < 0) { --it; ++n; }
}

template <typename Iterator, typename Distance>
void my_advance(Iterator& it, Distance n) {
    using category = typename std::iterator_traits<Iterator>::iterator_category;
    advance_impl(it, n, category());
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type my_distance(Iterator first, Iterator last) {
    if constexpr (std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>) {
        std::cout << "[O(1) Subtraction used]\n";
        return last - first;
    } else {
        std::cout << "[O(N) Counting Loop used]\n";
        typename std::iterator_traits<Iterator>::difference_type dist = 0;
        while(first != last) { ++first; ++dist; }
        return dist;
    }
}

} // namespace mystl