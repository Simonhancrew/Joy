class Solution {
 public:
  bool checkPartitioning(string s) {
    int n = s.size();
    vector<vector<int>> f(n, vector<int>(4, -1));
    vector<vector<int>> ff(n, vector<int>(n, -1));
    auto check = [&](this auto &&check, int l, int r) -> bool {
      if (l >= r) {
        return true;
      }
      auto &res = ff[l][r];
      if (res != -1) {
        return res;
      }
      res = (s[l] == s[r] && check(l + 1, r - 1));
      return res;
    };
    auto dfs = [&](this auto &&dfs, int i, int cnt) -> bool {
      if (cnt == 1) {
        return check(i, n - 1);
      }
      if (i >= n) {
        return false;
      }
      auto &res = f[i][cnt];
      if (res != -1) {
        return res;
      }
      res = false;
      for (int j = i; j + 1 < n; j++) {
        if (check(i, j)) {
          res |= dfs(j + 1, cnt - 1);
        }
      }
      return res;
    };
    return dfs(0, 3);
  }
};
