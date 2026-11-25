#include<iostream>
#include<map>
#include<string>
#include<utility>

struct Edge{
  unsigned long v1;
  unsigned long v2;

  Edge(){
    v1 = -1;
    v2 = -1;
  }

  Edge(unsigned long _v1, unsigned long _v2) : v1(_v1), v2(_v2){
  }

  bool operator<(const Edge& rhs) const{
    return v1 + v2 < rhs.v1 + rhs.v2;
  }

  friend std::ostream& operator<<(std::ostream& os, const Edge& e);
};

std::ostream& operator<<(std::ostream& os, const Edge& e){
  os << e.v1 << ", " << e.v2;
  return os;
}

struct EdgeCompare{
  bool operator()(const Edge& lhs, const Edge& rhs)const{
    return lhs.v1 + lhs.v2 < rhs.v1 + rhs.v2;
  }
};

int main(){

  std::map<std::string, Edge> mymap;

  mymap["edge1"] = Edge(0, 0);
  std::cout << mymap["edge1"] << std::endl;

  mymap["edge1"] = Edge(1, 1);
  std::cout << mymap.at("edge1") << std::endl;

  mymap.insert(std::pair("edge2", Edge(2, 2)));
  std::cout << mymap.at("edge2") << std::endl;

  const auto[it, success] = mymap.insert(std::pair("edge3", Edge(3, 3)));
  std::cout << "edge 3 was added: " << success << std::endl;

  std::cout << (*it).first << std::endl;

  std::cout << it->second << std::endl;

  for(auto const& [key, val] : mymap){
    std::cout << key << " => (" <<  val << ")" << std::endl;
  }

  for(std::map<std::string, Edge>::iterator it = mymap.begin(); it != mymap.end(); ++it){
    std::cout << it->first << std::endl;
  }

  std::map<Edge, std::string> mymap2;

  Edge e1(8, 8);
  mymap2[e1] = "test";

  std::map<Edge, std::string, EdgeCompare> mymap3;
  mymap3[e1] = "custom_compare_test"; 
  return 0;
}
