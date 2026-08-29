#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> B(m);
    for (int j = 0; j < m; j++) cin >> B[j];

    // Compute the DP matrix tracking the lengths
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to reconstruct the longest common subsequence
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]); // Part of LCS
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    // Since we backtracked from the end, the elements are reversed
    reverse(lcs.begin(), lcs.end());

    // Print the result elements separated by space
    for (int k = 0; k < lcs.size(); k++) {
        cout << lcs[k] << (k == lcs.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
