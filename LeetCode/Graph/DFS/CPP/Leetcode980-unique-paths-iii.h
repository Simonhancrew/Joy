#include <functional>
#include <vector>


using namespace std;

class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  int uniquePathsIII(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> st(n, vector<int>(m, 0));
    int sx = 0, sy = 0, ex = 0, ey = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          sx = i, sy = j;
          g |= (1 << (sx * m + sy));
        } else if (grid[i][j] == 2) {
          ex = i, ey = j;
        } else if (grid[i][j] == -1) {
          g |= (1 << (i * m + j));
        }
      }
    }
    // cout << bitset<12>(g) << endl;
    st[sx][sy] = 1;
    int ans = 0;
    function<void(int, int)> dfs = [&](int x, int y) {
      if (x == ex && y == ey) {
        // cout << bitset<11>(g) << endl;
        if (g == (1 << (n * m)) - 1) ans++;
        return;
      }
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || ny >= m || nx >= n) continue;
        if (grid[nx][ny] == -1 || st[nx][ny]) continue;
        st[nx][ny] = 1;
        g |= (1 << (nx * m + ny));
        dfs(nx, ny);
        st[nx][ny] = 0;
        g ^= (1 << (nx * m + ny));
      }
    };
    dfs(sx, sy);
    return ans;
  }
};
