#include<iostream>

 int main(){
   std::cout << "hello" << std::endl;
   int64_t x = 1234567897;
   std::cout << x << std::endl;
   float t = 321.5f; // ye pehle nhi aata tha
   std::cout << t << std::endl;
   char a = 'abc';
   std::cout << a << std::endl;
   const char* b = "abcd";
   std::cout << b << std::endl;
   std::cout << sizeof(b) << std::endl;
   return 0;
 }
