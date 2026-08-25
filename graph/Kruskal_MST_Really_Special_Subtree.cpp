#include "utility.h"
#include <iterator>
#include <vector>
#include <algorithm>
#include <tuple>

#define ll long long int
using namespace std;

int find(vector<int>& parent, int a){
  return parent[a] = (parent[a] == a ? a : find(parent, parent[a]));
}

void Union(vector<int>& par, vector<int>& rank, int a, int b){
  a = find(par, a);
  b = find(par, b);
  if(a == b) return;

  if(rank[a] >= rank[b]){
    rank[a]++;
    par[b] = a;

  }else{
    rank[b]++;
    par[a] = b;
  }
}

struct Edge{
  int src, dest, wt;
};

bool cmp(Edge e1, Edge e2){
  return e1.wt < e2.wt;
}

ll kruskal(vector<Edge>& inp, int n, int e){
  sort(inp.begin(), inp.end(), cmp);

  vector<int> par(n + 1);
  vector<int> rank(n + 1, 1);

  for(int i = 0; i <= n; ++i) par[i] = i;

  int edgeCount = 0; // n - 1
  int i = 0;
  ll ans = 0;
  while(edgeCount < n - 1 && i < inp.size()){
    Edge curr = inp[i];// becouse input is sorted so we will get min weight edge
    int srcPar = find(par, curr.src);
    int destPar = find(par, curr.dest);

    if(srcPar != destPar){
      // include edge as this will not make cycle
      Union(par, rank, srcPar, destPar);
      ans += curr.wt;
      edgeCount++;
    }
    i++; // does not mattar picked or not picked -> go to nect edge
  }
  return ans;
} 

int main(){
  ios_base::sync_with_stdio;
  cin.tie(NULL);

  int n, e;
  cin >> n >> e;
  vector<Edge> v(e);
  for(int i = 0; i < e; ++i) cin >> v[i].dest >> v[i].dest >> v[i].wt;
  cout << kruskal(v, n, e) << "\n";

  return 0;
}
