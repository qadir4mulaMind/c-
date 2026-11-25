#include<iostream>
#include<queue>
#include<vector>

struct Edge{
  int v1, v2;
  Edge(int _v1, int _v2) : v1(_v1), v2(_v2) {}

  friend std::ostream& operator << (std::ostream& os, const Edge& e);
};

std::ostream& operator<<(std::ostream& os, const Edge& e){
  os << e.v1 << "," << e.v2;
  return os;
}

struct EdgeCompare{
  bool operator()(const Edge& e1, const Edge& e2) const{
    int e1Sum = e1.v1 + e1.v2;
    int e2Sum = e2.v1 + e2.v2;
    return e1Sum < e2Sum;
  }
};

int main(){
  std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> edges;
  Edge e1(1, 1);
  Edge e2(2, 2);
  Edge e3(3, 3);

  edges.push(e1);
  edges.push(e2);
  edges.push(e3);

  while(!edges.empty()){
    Edge topEdge = edges.top();
    std::cout << topEdge << std::endl;
    edges.pop();
  }

  return 0;
}
