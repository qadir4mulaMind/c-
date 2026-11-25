#include<iostream> 
#include<vector>

int main(){
  std::vector<int> v;
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);

  std::cout <<"Size of data structure: " << sizeof(v) << std::endl;
  std::cout << "Size of object: " <<  v.size() << std::endl;

  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  std::cout <<"Size of data structure: " << sizeof(v) << std::endl;
  std::cout << "Size of object: " <<  v.size() << std::endl;
  return 0;
}
