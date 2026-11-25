#include<iostream>
#include<stack>


int main(){
  std::stack<int> st({0, 9, 8, 7, 6});

  st.push(1);
  st.push(2);
  st.push(3);

  std::cout << st.top() << std::endl;
  st.pop();
  std::cout << st.top() << std::endl;

  while(not st.empty()){
    std::cout << st.top() << std::endl;
    st.pop();
  }
  return 0;
}
