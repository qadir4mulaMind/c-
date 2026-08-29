#include <cstddef>
#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // dp[mask] stores {min_rides, min_weight_of_last_ride}
    vector<pair<int, long long>> dp(1 << n);
    
    // Base case: 0 people require 1 ride with 0 weight inside it
    dp[0] = {1, 0};

    // Iterate through all possible subsets of people
    for (int mask = 1; mask < (1 << n); mask++) {
        // Initialize with a worst-case scenario (infinity placeholder)
        dp[mask] = {n + 1, 0}; 

        for (int i = 0; i < n; i++) {
            // Check if the i-th person is included in the current subset
            if (mask & (1 << i)) {
                auto prev = dp[mask ^ (1 << i)];
                int rides = prev.first;
                long long last_weight = prev.second;

                // Determine the cost if person i is added last
                if (last_weight + w[i] <= x) {
                    last_weight += w[i];
                } else {
                    rides++;
                    last_weight = w[i];
                }

                // Keep the optimal pair (lexicographically smallest)
                dp[mask] = min(dp[mask], {rides, last_weight});
            }
        }
    }

    // The answer is the minimum rides required for the full set (all bits set)
    cout << dp[(1 << n) - 1].first << "\n";

    return 0;
}
