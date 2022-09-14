#include <vector>

using namespace std;

class Solution {
 public:
  const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
  int n, m;
  int dfs(int x, int y, vector<vector<int>>& grid, bool& tag) {
    int sum = 1;
    if (!tag && (x == 0 || y == 0 || x == n - 1 || y == m - 1)) tag = true;
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (!grid[nx][ny]) continue;
      sum += dfs(nx, ny, grid, tag);
    }
    return sum;
  }

  int numEnclaves(vector<vector<int>>& grid) {
    int ans = 0;
    n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          bool tag = false;
          int sum = dfs(i, j, grid, tag);
          if (!tag) ans += sum;
        }
      }
    }
    return ans;
  }
};