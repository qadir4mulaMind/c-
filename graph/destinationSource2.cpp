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

bool canReachDestinationPointers(vector<vector<char>>& grid){
  // grid khali to nhi hai
  if(grid.empty() || grid[0].empty()) return false;
  int m = grid.size();
  int n = grid[0].size();

  // Base Case: 1x1 grid means we are already at the target
  if(m == 1 && n == 1) return true;
  Cell slow = {0, 0};
  Cell fast = {0, 0};

  while (true){
    // --- Move Slow Pointer 1 Step ---
    if(! isvalid(slow.r, slow.c, m , n)) return false;
    slow = GetNextStep(slow.r, slow.c, grid[slow.r][slow.c]);
    if(slow.r == m - 1 && slow.c == n - 1) return true; 

    // --- Move Fast Pointer Step 1 ---
    if(!isvalid(fast.r, fast.c, m, n)) return false;
    fast = GetNextStep(fast.r, fast.c, grid[fast.r][fast.c]);
    if(fast.r == m -1 && fast.c == n - 1) return true;

    // --- Move Fast Pointer Step 2 ---
    if(! isvalid(fast.r, fast.c, m, n)) return false;
    fast = GetNextStep(fast.r, fast.c, grid[fast.r][fast.c]);
    if(fast.r == m - 1 && fast.c == n - 1) return true;

    // --- Cycle Detection Check ---
    if(slow == fast) return false;
  }
  
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
        cout << canReachDestinationPointers(grid) << "\n";
    }
  return 0;
}