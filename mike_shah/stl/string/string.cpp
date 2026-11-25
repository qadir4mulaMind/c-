#include<iostream>
#include<string>

// heeping in  mind passing string by const  refrance if we want to only read
void print_string(const std::string& s){
  std::cout << s << std::endl;
}


int main(){

  std::string s1 = "mike";
  std::string s2("qadir");

  std::cout << s1 << std::endl;
  std::cout << s1.size() << std::endl;
  s1.shrink_to_fit();
  std::cout << s1.capacity() << std::endl << std::endl;

  std::cout << s2 << std::endl;
  std::cout << s2.size() << std::endl;
  s2 += "dsjskdjbksdjsnckjsdvkdjnkvjdfnvbjdnk";
  s2 += "dsjskdjbksdjsnckjsdvkdjnkvjdfnvbjdnk";
  s2.shrink_to_fit();
  std::cout << s2.capacity() << std::endl << std::endl;
  std::cout << s2 << std::endl;

  std::cout << std::endl;

  std::cout << s1.c_str() << std::endl;

  s1[0] = 'M';
  std::cout << std::endl << s1 << std::endl;

  std::cout << std::endl << s1.data()[0] << std::endl;

  std::cout << std::endl << &(s1.data()[0]) << std::endl << std::endl;

  for(auto ele : s1){
    std::cout << ele << std::endl;
  }

  std::cout << std::endl;

  std::cout << s1.find("M") << std::endl << std::endl;

  std::cout << s1.find("z") << std::endl << std::endl;

  if(s1.find("z") == std::string::npos){
    std::cout << "Not find z\n " << std::endl;
  }else{
    std::cout << "fond z\n" << std::endl;
  }

  return 0;
}
