#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if (bi_dir){
        graph[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int> &visited){
    visited.insert(node);
    for (auto negh : graph[node]){
        // FIX 1: Only visit the neighbour if it hasn't been visited yet
        if (visited.count(negh) == 0){
            dfs(negh, visited);
        }
    }
}

int connected_component(){
    int result = 0;
    unordered_set<int> visited;
    for (int i = 0; i < v; i++){
        if (visited.count(i) == 0){
            result++;
            dfs(i, visited);
        }
    }
    return result;
}

int main(){
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> v))
        return 0;
    graph.resize(v, list<int>());

    int e;
    if (!(cin >> e)) return 0;

    // FIX 2: Use e-- so the loop actually terminates
    while (e--){
        int s, d;
        // FIX 3: Correct way to chain inputs in C++
        cin >> s >> d;
        add_edge(s, d, false);
    }

    cout << connected_component() << "\n";

    return 0;
}
