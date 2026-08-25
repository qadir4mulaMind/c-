#include "utility.h"

using namespace std;

// Disjoint Set Union (DSU) Structure
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int components; // Connected components ka total count track karne ke liye

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        components = n; // Shuruat mein har city apne aap mein ek alag component hai
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    // Find operation path compression ke saath
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); 
    }

    // Union operation by rank ke saath
    bool unionSets(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            // Jab do alag components aapas mein judte hain, toh total count 1 kam ho jata hai
            components--; 
            return true;
        }
        return false; // Agar pehle se connected hain (cycle), toh false return hoga
    }

    // Function jo check karega ki abhi kitne disjoint components bache hain
    int getComponentsCount() {
        return components;
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Step 1: Sabhi connections ko unki cost (index 2) ke basis par chote se bada sort karein
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        DisjointSet ds(n);
        int total_cost = 0;

        // Step 2: Kruskal's Algorithm loop
        for (const auto& connection : connections) {
            int city1 = connection[0];
            int city2 = connection[1];
            int cost = connection[2];

            // Agar dono cities alag components mein hain, toh unhe connect karein
            if (ds.unionSets(city1, city2)) {
                total_cost += cost;
                
                // Optimization: Agar bache hue components ghat kar 1 ho gaye hain,
                // matlab saari cities connect ho chuki hain. Hum yahin ruk sakte hain.
                if (ds.getComponentsCount() == 1) {
                    return total_cost;
                }
            }
        }

        // Final verification: Loop khatam hone ke baad agar exact 1 component bacha hai
        // toh total cost return karein, warna -1 (disconnected islands reh gaye hain)
        return ds.getComponentsCount() == 1 ? total_cost : -1;
    }
};

int main() {
    // Fast I/O for CPH
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> connections(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> connections[i][0] >> connections[i][1] >> connections[i][2];
    }

    Solution sol;
    cout << sol.minimumCost(n, connections) << "\n";

    return 0;
}
