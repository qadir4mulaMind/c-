#include "utility.h"

using namespace std;

// Find operation with Path Compression (Required internally by Union)
int find(vector<int>& parent, int x) {
    return (parent[x] == x) ? x : (parent[x] = find(parent, parent[x]));
}

// Union operation by Rank (Returns true if a cycle is detected)
bool Union(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a == b) return true; // Cycle detected

    // Union by Rank optimization
    if (rank[a] > rank[b]) {
        parent[b] = a;
    } else if (rank[b] > rank[a]) {
        parent[a] = b;
    } else {
        parent[b] = a;
        rank[a]++; 
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0; 
    
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        
        if (Union(parent, rank, x, y)) {
            cout << "Cycle Detection\n";
        }
    }

    return 0;
}
