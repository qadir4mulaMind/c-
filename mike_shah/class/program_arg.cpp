#include<iostream>

int main(int argc, char* argv[], char* env[]){

  std::cout << "argc " << argc << std::endl;

  for(size_t i = 0; i < argc; i++){
    std::cout << "[" << i << "]" << std::endl;
  }

  std::cout << "\nenv " << *env << std::endl;

  std::cout << std::getenv("PATH") << std::endl;

  int i = 0;
  for(;;){
    std::cout << env[i++];
    if(env[i] == nullptr){
      break;
    }
    break;
  }
  return 0;
}
