class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    int ans = 0;
    vector<vector<int>> g(n, vector<int>(n, 1));
    for (auto x : mines) g[x[0]][x[1]] = 0;
    vector<vector<int>> f(n, vector<int>(n));
    // line, left 2 right
    for (int i = 0; i < n; i++) {
      for (int j = 0, s = 0; j < n; j++) {
        if (g[i][j])
          s++;
        else
          s = 0;
        f[i][j] = s;
      }
    }
    // line right 2 left
    for (int i = 0; i < n; i++) {
      for (int j = n - 1, s = 0; j >= 0; j--) {
        if (g[i][j])
          s++;
        else
          s = 0;
        f[i][j] = min(f[i][j], s);
      }
    }
    // col, top 2 down
    for (int j = 0; j < n; j++) {
      for (int i = 0, s = 0; i < n; i++) {
        if (g[i][j])
          s++;
        else
          s = 0;
        f[i][j] = min(f[i][j], s);
      }
    }
    // col, down 2 top
    for (int j = 0; j < n; j++) {
      for (int i = n - 1, s = 0; i >= 0; i--) {
        if (g[i][j])
          s++;
        else
          s = 0;
        f[i][j] = min(f[i][j], s);
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res = max(res, f[i][j]);
      }
    }
    return res;
  }
};
