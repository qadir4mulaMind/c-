#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>

void test0(){
  {
    std::ofstream myFile("myFile.txt");
    myFile << "Hi EveryOne my name is Abdul Qadir.\n";
    myFile << "Can you plaese tell me about yourself?\n";
    myFile.close();
  }

  {
    std::ifstream f("myFile.txt");
    if(f.is_open() && std::filesystem::exists("myFile.txt")){
      std::string line;
      while(std::getline(f, line)){
        std::cout << line << std::endl;
      } 
    } else{
      std::cerr << "file does'nt exists" << std::endl;
    }
  }

  {
    std::ofstream myFile("myFile2.txt");
    myFile << "2 3 4\n";
    myFile << "5 7 8\n";
    myFile << "10 11 12\n";
    myFile.close();
  }

  {
    std::ifstream f("myFile2.txt");
    if(f.is_open() && std::filesystem::exists("myFile.txt")){
      int x, y, z;
      while(f >> x >> y >> z){
        std::cout << x << ","
                  << y << "," 
                  << z << std::endl;
      }
    } else{
      std::cerr << "file does'nt exists" << std::endl;
    }
  }
}

int main(){
  test0();
  return 0;
} 
