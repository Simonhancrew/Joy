class Solution {
 public:
  static const int N = 1e2 + 10;
  int s[N][N];
  int get(int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]; }
  int largest1BorderedSquare(vector<vector<int>>& grid) {
    memset(s, 0, sizeof s);
    int n = grid.size(), m = grid[0].size();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
      }
    }
    for (int len = min(m, n); len > 1; len--) {
      for (int i = 1; i + len - 1 <= n; i++) {
        for (int j = 1; j + len - 1 <= m; j++) {
          int a = i, b = j, c = a + len - 1, d = b + len - 1;
          if (get(a, b, c, d) - get(a + 1, b + 1, c - 1, d - 1) == 4 * (len - 1)) {
            return len * len;
          }
        }
      }
    }
    if (s[n][m] > 0) return 1;
    return 0;
  }
};
