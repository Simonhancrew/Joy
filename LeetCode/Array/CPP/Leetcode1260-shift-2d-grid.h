class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans = grid;
    while (k--) {
      for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
          ans[i][j] = grid[i][j - 1];
        }
      }
      int t = grid[n - 1][m - 1];
      for (int i = 1; i < n; i++) {
        ans[i][0] = grid[i - 1][m - 1];
      }
      ans[0][0] = t;
      grid = ans;
    }
    return ans;
  }
};