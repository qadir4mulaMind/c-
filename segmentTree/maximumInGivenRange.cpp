#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<iomanip>
#include<climits>
using namespace std;

vector<int> st;

void buildTree(int arr[], int i , int lo, int hi){
    if(lo == hi){ // base case
        st[i] = arr[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;

    buildTree(arr, 2 * i + 1, lo, mid); // left subtree
    buildTree(arr, 2 * i + 2, mid + 1, hi); // right subtree

    st[i] = max(st[2 * i + 1], st[2 * i + 2]);
}

int getMax(int i, int lo, int hi, int& l, int& r){
    if(l > hi or r < lo) return INT_MIN;
    if(lo >= l && hi <= r) return st[i];

    int mid = lo + (hi - lo) / 2;

    return max(getMax(2 * i + 1, lo, mid, l, r), getMax(2 * i + 2, mid + 1, hi, l, r));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    st.resize(4 * n);
    buildTree(arr, 0, 0, n - 1);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << getMax(0, 0, n - 1, l, r) << "\n";
    }

    return 0;
}