#include<iostream>
#include<vector>

int main(){

 std::vector<int> v(1, 2, 3, 4);

 for(auto& i : v){
   std::cout << i << "\n";
 }

  return 0;
}
