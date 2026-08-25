#include "utility.h"
#include <queue>

using namespace std;

vector<list<int>> graph;
int v; // no of vertices

void add_edge(int src, int dest, bool bdir = true){
  graph[src].push_back(dest);
  if(bdir){
    graph[dest].push_back(src);
  }
}

// Pure BFS Cycle Detection for a single component
bool bfs_cycle_check(int src, unordered_set<int>& visited) {
  queue<int> q;
  // Parent vector to keep track of who discovered whom
  vector<int> parent(v, -1);

  q.push(src);
  visited.insert(src);

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(auto neighbour : graph[node]) {
      // 1. Agar neighbour visited hai aur current node ka parent nahi hai -> CYCLE!
      if(visited.count(neighbour) && neighbour != parent[node]) {
        return true; 
      }
      
      // 2. Agar neighbour visited nahi hai, toh use queue mein daalein
      if(!visited.count(neighbour)) {
        visited.insert(neighbour);
        parent[neighbour] = node; // Track parent
        q.push(neighbour);
      }
    }
  }
  return false;
}

// Function to handle disconnected components as well
bool has_cycle() {
  unordered_set<int> visited;
  
  for(int i = 0; i < v; ++i) {
    if(!visited.count(i)) {
      if(bfs_cycle_check(i, visited)) {
        return true;
      }
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
      add_edge(s, d, true); // Undirected graph for standard parent cycle check
    }
    
    if(has_cycle()) {
        cout << "Cycle Detected!\n";
    } else {
        cout << "No Cycle Found.\n";
    }
  }
  return 0;
}
