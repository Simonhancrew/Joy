class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int ans = 0;
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> f(n, vector<int>(m, -1));
    auto dfs = [&](auto &&dfs, int x, int y) {
      if (x == n - 1 && y == m - 1) {
        return 1;
      }
      int &ans = f[x][y];
      if (ans != -1) {
        return ans;
      }
      ans     = 0;
      auto nx = x + 1, ny = y;
      if (nx < n && obstacleGrid[nx][ny] == 0) {
        ans += dfs(dfs, nx, ny);
      }
      nx = x, ny = y + 1;
      if (ny < m && obstacleGrid[nx][ny] == 0) {
        ans += dfs(dfs, nx, ny);
      }
      return ans;
    };
    return dfs(dfs, 0, 0);
  }
};
