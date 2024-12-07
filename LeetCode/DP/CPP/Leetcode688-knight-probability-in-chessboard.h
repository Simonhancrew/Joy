class Solution {
 public:
  static constexpr int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
  static constexpr int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  using LL                   = long long;
  double f[101][25][25]{};
  double knightProbability(int n, int k, int row, int column) {
    auto dfs = [&](auto &&dfs, int cnt, int x, int y) {
      if (cnt == 0) {
        return 1.0;
      }
      if (f[cnt][x][y]) {
        return f[cnt][x][y];
      }
      auto &res = f[cnt][x][y];
      for (int i = 0; i < 8; i++) {
        auto nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
          continue;
        }
        res += dfs(dfs, cnt - 1, nx, ny);
      }
      res /= 8.0;
      return res;
    };
    return dfs(dfs, k, row, column);
  }
};
