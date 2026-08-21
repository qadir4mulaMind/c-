#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
#include<climits> // Fixed: Added for INT_MAX

using namespace std;

vector<list<int>> graph;
int v; 
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
   graph[src].push_back(dest);
   if(bi_dir){
      graph[dest].push_back(src);
   }
}

void bfs(int src, int dest, vector<int> & dist){
   queue<int> qu;
   visited.clear();
   dist.assign(v, INT_MAX); // Fixed: Keeps vector resized and resets values accurately
   dist[src] = 0;
   visited.insert(src);
   qu.push(src);
   
   // Fixed: Changed from qu.empty() to !qu.empty()
   while(!qu.empty()){
      int curr = qu.front();
      qu.pop();
      for(auto negh : graph[curr]){
         if(not(visited.count(negh))){
            qu.push(negh);
            visited.insert(negh);
            dist[negh] = dist[curr] + 1;
         }
      }
   }
}

int main(){
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while(e--){
        int s;
        int d;
        cin >> s >> d;
        add_edge(s, d);
    }

    int x, y;
    cin >> x >> y;
    vector<int> dist;

    bfs(x, y, dist);
    for(int i = 0; i < dist.size(); i++){
       cout << dist[i] << " ";
    }
    return 0;
}
