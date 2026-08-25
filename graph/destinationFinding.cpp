#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Helper structure to keep tracking code clean
struct Cell{
  int r, c;
  bool operator == (const Cell& other) const{
    return r == other.r && c == other.c;

  }
};

// Helper function to find the next cell coordinates based on direction
Cell GetNextStep(int r, int c, char dir){
  if(dir == 'R') return {r, c + 1};
  if(dir == 'L') return {r, c - 1};
  if(dir == 'U') return {r - 1, c};
  if(dir == 'D') return {r + 1, c};
  return {r, c}; 
}

// Helper function to check grid boundaries
bool isvalid(int r, int c, int m, int n){
  return r >= 0 && r < m && c >= 0 && c < n;
}

// ----------------------------------------------------
// Approach 1: M * N Step Counter
// ----------------------------------------------------
bool canReachDestinationCounter(vector<vector<char>>& grid){
  if(grid.empty() || grid[0].empty()) return false;

  int m = grid.size();
  int n = grid[0].size();
  int r = 0, c = 0;
  long long maxSteps = static_cast<long long> (m) * n;

  for(long long step = 0; step < maxSteps; step++){
    // checking if we reach the destination or not
    if(r == m - 1 && c == n - 1) return true;

    // checking the boundry
    if(!isvalid(r, c, m, n)) return false;

    // Advance to  the next cell
    Cell next = GetNextStep(r, c, grid[r][c]);
    r = next.r;
    c = next.c;
  }
  // there will definatly be a loop or other boundry issue
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
    if (std::cin >> m >> n) {
        vector<vector<char>> grid(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        
        // Kisi ek approach ko call karein
        cout << canReachDestinationCounter(grid) << "\n";
    }
  return 0;
}