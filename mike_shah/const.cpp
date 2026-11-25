#include<iostream>
 
 int main(){
   const float PI = 3.141526f;
   std::cout << PI << std::endl;
   PI = -42;
   std::cout << PI << std::endl;
   return 0;
 }
