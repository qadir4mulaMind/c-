#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Optimized with Path Compression
int find(vector<int>& parent, int x) {
    return (parent[x] == x) ? x : (parent[x] = find(parent, parent[x]));
}

// Optimized with accurate Union by Rank
void Union(vector<int>& parent, vector<int>& rank, vector<int>& sz, vector<int>& minimal, vector<int>& maximal, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) { 
        if (rank[a] >= rank[b]) {
            if (rank[a] == rank[b]) rank[a]++;
            parent[b] = a;         
            sz[a] += sz[b];          
            maximal[a] = max(maximal[a], maximal[b]);
            minimal[a] = min(minimal[a], minimal[b]);
        } else {
            parent[a] = b;
            sz[b] += sz[a];
            maximal[b] = max(maximal[a], maximal[b]);
            minimal[b] = min(minimal[a], minimal[b]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0; 
    
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    vector<int> sz(n + 1, 1);     
    vector<int> minimal(n + 1);
    vector<int> maximal(n + 1); 

    for (int i = 1; i <= n; i++) {
        parent[i] = minimal[i] = maximal[i] = i;
    }

    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, sz, minimal, maximal, x, y);
        } else {
            int x;
            cin >> x;
            int root = find(parent, x); 
            cout << minimal[root] << " " << maximal[root] << " " << sz[root] << "\n";
        }
    }

    return 0;
}
