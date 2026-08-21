#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm> // For reverse()
#include<climits>

using namespace std;

vector<list<int>> graph;
int v; 
vector<bool> visited; // Changed to bool vector for faster lookup

void add_edge(int src, int dest, bool bi_dir = true){
   graph[src].push_back(dest);
   if(bi_dir){
      graph[dest].push_back(src);
   }
}

// Added 'parent' vector to track paths
void bfs(int src, vector<int> &dist, vector<int> &parent){
   queue<int> qu;
   visited.assign(v, false);
   dist.assign(v, INT_MAX);
   parent.assign(v, -1); // -1 means no parent
   
   dist[src] = 0;
   visited[src] = true;
   qu.push(src);
   
   while(!qu.empty()){
      int curr = qu.front();
      qu.pop();
      
      for(auto negh : graph[curr]){
         if(!visited[negh]){
            qu.push(negh);
            visited[negh] = true;
            dist[negh] = dist[curr] + 1;
            parent[negh] = curr; // Track where we came from
         }
      }
   }
}

// Function to reconstruct and print the path from source to target
void print_path(int target, const vector<int> &parent) {
    if (parent[target] == -1) {
        cout << target;
        return;
    }
    
    vector<int> path;
    int curr = target;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    
    reverse(path.begin(), path.end());
    
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
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

    int x; // Source node
    cin >> x; 
    
    vector<int> dist;
    vector<int> parent;

    bfs(x, dist, parent);
    
    cout << "\n--- Results from Source Node " << x << " ---\n";
    for(int i = 0; i < v; i++){
       cout << "Node " << i << ": ";
       if (dist[i] == INT_MAX) {
           cout << "Distance = Unreachable | Path = No Path\n";
       } else {
           cout << "Distance = " << dist[i] << " | Path = ";
           print_path(i, parent);
           cout << "\n";
       }
    }
    return 0;
}
