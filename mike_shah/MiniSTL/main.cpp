#include <iostream>
#include <sstream>
#include <algorithm>
#include "include/MyVector.hpp"
#include "include/MyList.hpp"
#include "include/MyIterators.hpp"

int main() {
    std::cout << "=== 1. TAG DISPATCHING: VECTOR (O(1)) VS LIST (O(N)) ===\n";
    mystl::MyVector<int> vec;
    vec.push_back(10); vec.push_back(20); vec.push_back(30); vec.push_back(40);
    
    mystl::MyList<int> lst;
    lst.push_back(10); lst.push_back(20); lst.push_back(30); lst.push_back(40);

    auto v_it = vec.begin();
    std::cout << "Vector advance(2): ";
    mystl::my_advance(v_it, 2);
    std::cout << "Value: " << *v_it << "\n";

    auto l_it = lst.begin();
    std::cout << "List advance(2): ";
    mystl::my_advance(l_it, 2);
    std::cout << "Value: " << *l_it << "\n\n";

    std::cout << "Vector distance: ";
    std::cout << mystl::my_distance(vec.begin(), vec.end()) << "\n";

    std::cout << "List distance: ";
    std::cout << mystl::my_distance(lst.begin(), lst.end()) << "\n\n";

    std::cout << "=== 2. MOVE ITERATOR ADAPTOR ===\n";
    mystl::MyVector<std::string> str_src;
    str_src.push_back("HeavyStringA");
    str_src.push_back("HeavyStringB");

    mystl::MyVector<std::string> str_dest;
    
    // std::copy with custom move iterator and back inserter
    std::copy(mystl::my_make_move_iterator(str_src.begin()), 
              mystl::my_make_move_iterator(str_src.end()), 
              mystl::my_back_inserter(str_dest));

    std::cout << "Source after move: '" << str_src[0] << "' (Empty means moved!)\n";
    std::cout << "Dest after move: '" << str_dest[0] << "'\n\n";

    std::cout << "=== 3. STREAM ITERATORS ===\n";
    std::string raw_data = "100 200 300";
    std::stringstream ss(raw_data);
    
    mystl::MyVector<int> stream_nums;
    std::copy(mystl::MyIstreamIterator<int>(ss), 
              mystl::MyIstreamIterator<int>(), 
              mystl::my_back_inserter(stream_nums));
              
    std::cout << "Read from stream: ";
    for (int n : stream_nums) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "Write to console: ";
    mystl::MyOstreamIterator<int> out_it(std::cout, " | ");
    *out_it = 999;
    *out_it = 888;
    std::cout << "\n";

    return 0;
}