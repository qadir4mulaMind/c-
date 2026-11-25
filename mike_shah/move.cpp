#include<iostream>
#include<string>

int main(){
  
  // Construct a new string.This uses copy constructor
  // we have a 'rvalue' on the right and that will be copied int 'mystring'
  // using the copy constructor
  
  std::string myString = "copy construct me";
  std::string newValue;

  std::cout << "myString : " << myString << std::endl;
  std::cout << "newValue : " << myString << std::endl;
  
  // std::move allow us to 'adopt' or 'steal' the value
  // newValue = std::move(myString);
  // could more explicitely call the static cast here the move 
  // the value of myString int newValue
  newValue = static_cast < std::string&& > (myString);
  // note: myString is still some 'valid' value.
  // Maybe it store 'nullptr' in the data in the string but is will still exist

  std::cout << "myString: " << myString << std::endl;
  std::cout << "newValue: " << newValue << std::endl;

  return 0;
}
