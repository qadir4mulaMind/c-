#include "person.hpp"
#include<iostream>

struct  Person::pImplPerson{
  std::string m_name;
  std::string m_strength;
  std::string m_speed;
};

Person::Person(std::string s){
  m_impl = std::make_unique<pImplPerson>();
  m_impl->m_name = s;
  m_impl->m_strength = "n/a";
  m_impl->m_speed = "n/a";
}

Person::~Person(){
}

std::string Person ::getAttributes(){
  return m_impl->m_name + "," +  m_impl->m_strength + "," +  m_impl->m_speed;
} 
