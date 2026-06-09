#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 16;
// Switched to long long to prevent integer overflow with 1,000,000,000 values
vector<long long> dp(1 << MAX_N, -1); 
vector<long long> sums(1 << MAX_N, 0);

long long calc(const vector<vector<int>>& compat, int mask, int n){
    long long ans = 0; 
    for(int i = 0; i < n; i++){
        if((mask & (1 << i))) {
            for(int j = i + 1; j < n; j++){ 
                if((mask & (1 << j))) {
                    ans += compat[i][j];
                }
            }
        }
    }
    return ans;
}

void preComput(const vector<vector<int>>& compat, int n){
    for(int i = 1; i < (1 << n); i++){
        sums[i] = calc(compat, i, n);
    }
}

long long f(const vector<vector<int>>& compat, int mask) {
    if(mask == 0) return 0;
    if(dp[mask] != -1) return dp[mask];

    long long ans = 0;
    for(int g = mask; g != 0; g = (g - 1) & mask) {
        ans = max(ans, sums[g] + f(compat, mask ^ g));
    }

    return dp[mask] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<vector<int>> compat(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> compat[i][j];
        }
    }

    preComput(compat, n);
    fill(dp.begin(), dp.begin() + (1 << n), -1);
    
    cout << f(compat, (1 << n) - 1) << "\n";

    return 0;
}
