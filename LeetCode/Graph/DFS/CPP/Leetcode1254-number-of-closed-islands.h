#include <functional>
#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  int closedIsland(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> st(n, vector<int>(m));
    function<void(int, int, bool&)> dfs = [&](int x, int y, bool& flag) {
      if (x == n - 1 || y == m - 1 || x == 0 || y == 0) flag = false;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (grid[nx][ny] == 1 || st[nx][ny]) continue;
        st[nx][ny] = true;
        dfs(nx, ny, flag);
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) continue;
        if (st[i][j]) continue;
        bool flag = true;
        dfs(i, j, flag);
        ans += flag;
      }
    }
    return ans;
  }
};
