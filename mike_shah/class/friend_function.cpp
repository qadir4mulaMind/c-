#include<iostream>

class UserDefinedDataType{
  public:
    UserDefinedDataType():  m_privateMemberVariables(0){};
    friend void printPrivateMemberVariablesOfUDP(UserDefinedDataType u);
  private:
    int m_privateMemberVariables;
};

void printPrivateMemberVariablesOfUDP(UserDefinedDataType u){
  std::cout << "m_privateMemberVariables: " << u.m_privateMemberVariables << std::endl;
}

int main(){

  UserDefinedDataType u1;
  printPrivateMemberVariablesOfUDP(u1);

  return 0;
}

