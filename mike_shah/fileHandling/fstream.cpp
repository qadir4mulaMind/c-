#include<fstream>
#include<iostream>

void test0(){
  std::ofstream myFile("myfile.txt");
  if(myFile.is_open()){
    std::cout << "FileHandler succesfully created\n";
  }
  myFile.put('w');
  myFile << "Hello mike\n";
  myFile << "Hello mike\n";
  myFile << "Hello mike\n";
  myFile << "Hello mike\n";
  myFile << "Hello mike\n";
  char a = 48;
  myFile << (int32_t)a;
  myFile.seekp(0);
  myFile << " ";
  myFile.seekp(-2, std::ios_base::end);
  myFile << 42;
}

int main(){
  test0();
  return 0;
}
