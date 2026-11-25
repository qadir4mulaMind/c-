#include<iostream>

int loadFile(/**/){
  return -1;
}

int main(){
  if(loadFile() == -1){
    std::cerr << "The file has an error.\n";
    std::cerr << "This is from std::cerr\n";
  }
  std::cout << "This is from std::cout\n";
  std::clog << "This is from std::clog\n";
  return 0;
}
