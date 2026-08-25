#include"utility.h"
#include <unordered_map>
#include <algorithm>

#define ll long long int
#define pp pair<int, int>

using namespace std;

vector<list<pp>> graph;

void add_edge(int u, int v, int wt, bool bdir = true){
  graph[u].push_back({v, wt});
  if(bdir) graph[v].push_back({u, wt});
}

unordered_map<int, int> dijkstra(int src, int n){
  priority_queue<pp, vector<pp>, greater<pp>> pq;
  unordered_set<int> visited;
  vector<int> via(n);
  unordered_map<int, int> mp;
  for(int i = 0; i < n; i++) mp[i] = INT_MAX;
  // 1. Pehle initialization thik karein
pq.push({0, src});
mp[src] = 0; 
while(!pq.empty()){
    pp curr = pq.top();
    pq.pop(); 
    
    int u = curr.second;
    int d = curr.first; 
    
    if(visited.count(u)) continue;
    visited.insert(u);
    
    for(auto neigh : graph[u]){
        int neighbor_vertex = neigh.first;
        int edge_weight = neigh.second;
        
        if(!visited.count(neighbor_vertex) and mp[neighbor_vertex] > (d + edge_weight)){
            mp[neighbor_vertex] = d + edge_weight;
            pq.push({mp[neighbor_vertex], neighbor_vertex});
            via[neighbor_vertex] = u;
        }
    }
}

  return mp;
}

int main(){
  int m, n;
  cin >> m >> n;
  graph.resize(m, list<pp>());


  while (n--){
    int u, v, wt;
    cin >> u >> v >>  wt;
    add_edge(u, v, wt);
  }
  
  int src;
  cin >> src;
  unordered_map<int, int> sp = dijkstra(src, m);
  int dest;
  cin >> dest;
  cout << sp[dest] << "\n";
  return 0;
}