class Solution {
 public:
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  int n, m;
  int ans = 0;
  vector<vector<bool>> st;
  int getMaximumGold(vector<vector<int>>& grid) {
    n = grid.size(), m = grid[0].size();
    st.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0 || st[i][j]) continue;
        st[i][j] = true;
        dfs(i, j, grid, grid[i][j]);
        st[i][j] = false;
      }
    }
    return ans;
  }
  void dfs(int x, int y, vector<vector<int>>& grid, int beg) {
    ans = max(ans, beg);
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (grid[nx][ny] == 0 || st[nx][ny]) continue;
      st[nx][ny] = true;
      dfs(nx, ny, grid, beg + grid[nx][ny]);
      st[nx][ny] = false;
    }
  }
};