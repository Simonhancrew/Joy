class Solution {
 public:
  int tilingRectangle(int n, int m) {
    vector<vector<int>> st(n, vector<int>(m, false));
    int ans = n * m;
    function<void(int, int, int, bool)> fill = [&st](int x, int y, int len,
                                                     bool val) {
      for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
          st[i][j] = val;
        }
      }
    };
    function<bool(int, int, int)> check = [&st](int x, int y, int len) {
      for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
          if (st[i][j]) return false;
        }
      }
      return true;
    };
    function<void(int, int, int)> dfs = [&](int x, int y, int cnt) {
      if (cnt > ans) return;
      if (y == m) x++, y = 0;
      if (x == n)
        ans = cnt;
      else {
        if (st[x][y])
          dfs(x, y + 1, cnt);
        else {
          for (int len = min(n - x, m - y); len; len--) {
            if (check(x, y, len)) {
              fill(x, y, len, true);
              dfs(x, y + 1, cnt + 1);
              fill(x, y, len, false);
            }
          }
        }
      }
    };
    dfs(0, 0, 0);
    return ans;
  }
};