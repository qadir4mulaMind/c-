#include"utility.h"

#define ll long long int
#define pp pair<int, int>

using namespace std;

vector<list<pp>> graph;

void add_edge(int u, int v, int wt, bool bdir = true){
  graph[u].push_back({v, wt});
  if(bdir) graph[v].push_back({u, wt});
}

ll prims(int src, int n){
  priority_queue<pp, vector<pp>, greater<pp>> pq;
  unordered_set<int> visited;
  vector<int> par(n);
  unordered_map<int, int> mp;
  for(int i = 0; i < n; i++) mp[i] = INT_MAX;
  pq.push({0, src});
  mp[src] = -1;
  int total_count = 0; // 0 -> n - 1
  int result = 0; // sum of weights
  while(total_count < n){
    pp curr = pq.top();
    if(visited.count(curr.second)){
      pq.pop();
      continue;
    }
    visited.insert(curr.second);
    total_count++;
    result += curr.first;
    pq.pop();
    for(auto neigh : graph[curr.second]){
      int neighbor_vertex = neigh.first;
      int edge_weight = neigh.second;

      if(!visited.count(neighbor_vertex) and mp[neighbor_vertex] > edge_weight){
        pq.push({edge_weight, neighbor_vertex});
        par[neighbor_vertex] = curr.second;
        mp[neighbor_vertex] = edge_weight;
      }
    }

  }
  return result;
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
  cout << prims(src, m) << "\n";
  return 0;
}