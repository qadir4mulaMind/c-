#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iomanip>

using namespace std;

const int mod = 1000000007;

int dp[22][1 << 22];

int f(int i, int mask, int n, vector<vector<int>>& c){

    if(i == n + 1){
        return (mask == 0);
    }

    if(dp[i][mask] != -1)
        return dp[i][mask];

    int ans = 0;

    for(int w = 1; w <= n; w++){

        bool avl = (mask & (1 << (w - 1)));

        if(avl && c[i][w]){

            ans = (ans + f(
                i + 1,
                mask ^ (1 << (w - 1)),
                n,
                c
            )) % mod;
        }
    }

    return dp[i][mask] = ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> c(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << f(1, (1 << n) - 1, n, c) << endl;

    return 0;
}