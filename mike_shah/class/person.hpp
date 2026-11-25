#ifndef PERSON_HPP
#define PERSON_HPP
#include<memory>
#include<string>

class Person{
  public:
    Person(std::string s);
    ~Person();
    std::string getAttributes();

  private:
    struct pImplPerson;
    std::unique_ptr<pImplPerson>m_impl;
};

#endif
