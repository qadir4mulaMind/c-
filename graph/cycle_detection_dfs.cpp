#include "utility.h"
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<list<int>> graph;
int v; // no of vertices

void add_edge(int src, int dest, bool bdir = true){
  graph[src].push_back(dest);
  if(bdir){
    graph[dest].push_back(src);
  }
}

void display(){
  for(int i = 0; i < graph.size(); ++i) {
    cout << i << " -> ";
    for(auto nbr : graph[i]) {
        cout << nbr << " ";
    }
    cout << "\n";
  }
}

bool dfs(int src, int parent, unordered_set<int>& visited){
  visited.insert(src);
  for(auto neighbour : graph[src]){
    if(visited.count(neighbour) && neighbour != parent){
      return true; // Cycle detection
    }
    if(!visited.count(neighbour)){
      // Recursive response ko check karke upar pass karna zaroori hai
      if(dfs(neighbour, src, visited)) return true;
    }
  }
  return false; 
}

bool has_cycle(){
  unordered_set<int> visited;
  for(int i = 0; i < v; ++i){
    if(!visited.count(i)){
      if(dfs(i, -1, visited)) return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  if (cin >> v) {
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while(e--){
      int s, d;
      cin >> s >> d; 
      add_edge(s, d, true); 
    }
    
    display();
    
    if(has_cycle()) {
        cout << "Cycle Detected!\n";
    } else {
        cout << "No Cycle Found.\n";
    }
  }
  return 0;
}
