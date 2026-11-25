#include<iostream>

class TopLevelClass{
  public:
    TopLevelClass(std::string args){
      std::cout << "TopLevelClass " << args << std::endl;
    }

    ~TopLevelClass(){
      std::cout << "TopLevelDestructor" << std::endl;
    }
};

class EntityBase : public TopLevelClass{
  public:

    EntityBase() : TopLevelClass("args1"){
      std::cout << "EntityBase Constructor " << std::endl;
    }

    EntityBase(std::string name) : TopLevelClass("args2"), m_name(name){
      std::cout << "EntityBase(name) constructor " << name << std::endl;
    }
    
    ~EntityBase(){
      std::cout << "EntityBase Destructor" << std::endl;
    }

  private:
    std::string m_name;
};

class Monstar : public EntityBase{
  public:

    Monstar() : EntityBase("Default"){
      std::cout << "Monstar Constructor" << std::endl;
    }
    
    ~Monstar(){
      std::cout << "Monstar Destructor" << std::endl;
    }
};

int main(){

  Monstar badMonstar;

  return 0;
}
