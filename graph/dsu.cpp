#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Optimized with Path Compression
int find(vector<int>& parent, int x) {
    // FIX: Saving the result directly back to parent[x] flattens the tree
    return (parent[x] == x) ? x : (parent[x] = find(parent, parent[x]));
}

// Optimized with accurate Union by Rank
void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) { // Only merge if they are in different sets
        if (rank[a] >= rank[b]) {
            parent[b] = a;
        } else if (rank[b] > rank[a]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            rank[a]++; // Rank only increases when joining sets of equal rank
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // Speeds up fast input/output
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0; 
    
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, x, y);
        } else {
            int x;
            cin >> x;
            cout << find(parent, x) << "\n";
        }
    }

    return 0;
}
