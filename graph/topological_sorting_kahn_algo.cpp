#include "utility.h"
using namespace std;

vector<list<int>> graph;
int v; // no of vertices
void add_edge(int a, int b, bool bdir = true){
  graph[a].push_back(b);
  if(bdir) graph[b].push_back(a);
}

void topoBFS(){
  // kahn algo
  vector<int> indegree(v, 0);
  for(int i = 0; i < v; ++i){
    for(auto neighbour : graph[i]){
      // ---------> neighbour 
      indegree[neighbour]++;
    }
  }


  queue<int> q;
  unordered_set<int> vis;
  for(int i = 0; i < v; ++i){
    if(indegree[i] == 0){
      q.push(i);
      vis.insert(i);
    }
  }

  while(not q.empty()){
    int node = q.front();
    cout << node << " ";
    q.pop();
    for(auto neighbour : graph[node]){
      if(not vis.count(neighbour)){
        indegree[neighbour]--;
        if(indegree[neighbour] == 0){
          q.push(neighbour);
          vis.insert(neighbour);
        }
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v;
  int e; 
  cin >> e;
  graph.resize(v, list<int>());
  while(e--){
    int x, y;
    cin >> x >> y;
    add_edge(x, y, false);
  }

   topoBFS();

  return 0;
}