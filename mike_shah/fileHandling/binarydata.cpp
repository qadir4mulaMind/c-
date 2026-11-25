#include<iostream>
#include<fstream>
#include<cstring>
#include<array>

void test0(){
  char char_array[256];
  std::array<int, 256> int_array;

  for(size_t i = 0; i < int_array.size(); i++){
    char_array[i] = i;
    int_array[i] = i;
  }

  std::fstream char_array_file("chardata.txt",std::ios::out);
  std::ofstream int_array_file("intdata.txt");

  for(size_t i = 0; i < int_array.size(); i++){
    char_array_file << char_array[i];
    int_array_file << int_array[i];
  }

  char_array_file.write(char_array, 256 * sizeof(char));
  int_array_file.write(reinterpret_cast<char*>(int_array.data()), 256 * sizeof(int));
}

int main(){
  test0();
  return 0;
}
