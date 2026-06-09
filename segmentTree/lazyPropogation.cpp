#include <iostream>
#include <vector>

class LazySegmentTree {
private:
    int n;
    std::vector<long long> tree;
    std::vector<long long> lazy;

    // Correctly pushes the pending update of the current node to its children
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Apply the lazy value to the current node's total sum
            tree[node] += (end - start + 1) * lazy[node];

            // If not a leaf node, pass the lazy value down to be ACCUMULATED by children
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            // Clear the lazy flag for this node
            lazy[node] = 0;
        }
    }

public:
    LazySegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        // 1. ALWAYS push pending updates first to maintain correct state sequence
        push(node, start, end); 

        // Out of bounds
        if (start > end || start > r || end < l) {
            return;
        }

        // 2. Total Overlap: safe to update because push() cleared this node's old lazy data
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        // 3. Partial Overlap
        int mid = start + (end - start) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        // ALWAYS push pending updates first before making evaluation choices
        push(node, start, end); 

        // Out of bounds
        if (start > end || start > r || end < l) {
            return 0; 
        }

        // Total Overlap
        if (start >= l && end <= r) {
            return tree[node];
        }

        // Partial Overlap
        int mid = start + (end - start) / 2;
        long long leftSum = queryRange(2 * node, start, mid, l, r);
        long long rightSum = queryRange(2 * node + 1, mid + 1, end, l, r);
        
        return leftSum + rightSum;
    }
};

int main() {
    int n = 6;
    LazySegmentTree st(n);

    // Update range [1, 3] by adding 5
    st.updateRange(1, 0, n - 1, 1, 3, 5);
    // Update range [2, 5] by adding 10
    st.updateRange(1, 0, n - 1, 2, 5, 10);

    // Query range [1, 4] -> expected sum output: 45
    std::cout << "Corrected Sum of range [1, 4]: " << st.queryRange(1, 0, n - 1, 1, 4) << std::endl;

    return 0;
}
