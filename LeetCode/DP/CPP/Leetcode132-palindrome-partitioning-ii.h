class Solution {
 public:
  int minCut(string s) {
    int n = s.size();
    vector<int> f(n, -1);
    vector<vector<int>> ff(n, vector<int>(n, -1));
    auto check = [&](auto &&check, int l, int r) -> bool {
      if (l >= r) {
        return true;
      }
      int &res = ff[l][r];
      if (res != -1) {
        return res;
      }
      return res = s[l] == s[r] && check(check, l + 1, r - 1);
    };
    auto dfs = [&](auto &&dfs, int i) {
      if (i == n) {
        return 0;
      }
      if (f[i] != -1) {
        return f[i];
      }
      int &res = f[i];
      res      = INT_MAX;
      for (int j = i; j < n; j++) {
        if (check(check, i, j)) {
          res = min(res, dfs(dfs, j + 1) + 1);
        }
      }
      return res;
    };
    return dfs(dfs, 0) - 1;
  }
};
