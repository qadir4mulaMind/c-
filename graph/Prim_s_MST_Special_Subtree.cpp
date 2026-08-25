#include "utility.h"

using namespace std;

// [weight, node] pair ke liye typedef
typedef pair<int, int> pii;

/*
 * HackerRank Function Template (Prim's Algorithm)
 * n: Number of nodes
 * edges: 2D vector jisme har element [u, v, weight] hai
 * start: Source vertex jahan se MST shuru karna hai
 */
int prims(int n, vector<vector<int>> edges, int start) {
    // Step 1: Adjacency List build karein -> graph[u] = list of {weight, v}
    // Note: weight ko pehle rakha hai taaki pair automatic weight se sort ho sake
    vector<vector<pii>> graph(n + 1);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        graph[u].push_back({wt, v});
        graph[v].push_back({wt, u}); // Undirected graph
    }

    // --- AAPKE PSEUDOCODE KE DATA STRUCTURES (DS) ---
    set<int> visited;                                         // DS - Visited - set
    priority_queue<pii, vector<pii>, greater<pii>> pq;        // priority_queue<pair> (Min-Heap)
    unordered_map<int, int> parent_map;                       // unordered_map for mapping

    int ans_weight = 0;

    // 1. insert the pair of <weight, src> in the priority_queue
    // Shuruat mein start node tak pahunchne ka weight 0 hoga
    pq.push({0, start}); 
    parent_map[start] = -1; // Source ka koi parent nahi hai

    while (!pq.empty()) {
        // 2. one by one remove the root element of the priority queue
        auto [wt, curr_node] = pq.top();
        pq.pop();

        // 3. if the root element already visited -> skip it
        if (visited.count(curr_node)) {
            continue;
        }

        // 4. we store the wt in the ans (Node ko visited mark karein aur weight add karein)
        visited.insert(curr_node);
        ans_weight += wt;

        // 5. go to every neighbour
        for (const auto& neighbor : graph[curr_node]) {
            int next_wt = neighbor.first;
            int next_node = neighbor.second;

            // Agar neighbour pehle se visited nahi hai
            if (!visited.count(next_node)) {
                pq.push({next_wt, next_node});
                
                // 6. updating the mapping (parent tree map update karein)
                parent_map[next_node] = curr_node;
            }
        }
    }

    return ans_weight;
}

int main() {
    // Fast I/O for HackerRank / CPH
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int start;
    cin >> start;

    cout << prims(n, edges, start) << "\n";

    return 0;
}
