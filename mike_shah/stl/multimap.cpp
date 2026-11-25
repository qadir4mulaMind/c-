#include<iostream>
#include<string>
#include<map>

int main(){
  using stringMutliMap = std::multimap<std::string, int>;
  std::multimap<std::string, int> mymultimap{{"mike", 2}, {"mike", 7}};
  mymultimap.insert(std::pair{"mike", 100});
  mymultimap.insert(std::pair{"tomoki", 117});
  mymultimap.insert(std::pair{"mike", 101});
  mymultimap.insert(std::pair{"mike", 102});
  mymultimap.insert(std::pair{"nike", 198});
  mymultimap.insert(std::pair{"mike", 103});

  std::cout << mymultimap.count("mike") << std::endl;
  
  //auto f = mymultimap.find("mike");
  
  //std::multimap<std::string, int> :: iterator f = mymultimap.find("mike");

  stringMutliMap::iterator f = mymultimap.find("mike");

  mymultimap.erase(f);

  for(const auto& element : mymultimap){
    std::cout << element.first << "," <<
      element.second << std::endl;
  }

  std::cout << mymultimap.count("mike") << std::endl;

  std::cout << "==========================================" << std::endl;

  auto firstEntry = mymultimap.lower_bound("mike");
  auto lastEntry = mymultimap.upper_bound("mike");

  for(; lastEntry != firstEntry; firstEntry++){
    std::cout << firstEntry-> first << "," << firstEntry-> second <<  std::endl;
  }
  
  return 0;
}
