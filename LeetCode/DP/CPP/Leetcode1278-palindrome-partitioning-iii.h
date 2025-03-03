class Solution {
 public:
  int palindromePartition(string s, int k) {
    int n = s.size();
    vector<vector<int>> f(n, vector<int>(k + 1, -1));
    vector<vector<int>> ff(n, vector<int>(n, -1));
    // NOTE: deducing this
    auto get = [&](this auto &&get, int l, int r) {
      if (l >= r) {
        return 0;
      }
      auto &res = ff[l][r];
      if (res != -1) {
        return res;
      }
      res = get(l + 1, r - 1) + (s[l] != s[r]);
      return res;
    };
    auto dfs = [&](this auto &&dfs, int i, int cnt) {
      if (cnt == 1) {
        return get(i, n - 1);
      }
      auto &res = f[i][cnt];
      if (res != -1) {
        return res;
      }
      res = 0x3f3f3f3f;
      for (int j = i; j + 1 < n; ++j) {
        res = min(res, get(i, j) + dfs(j + 1, cnt - 1));
      }
      return res;
    };
    return dfs(0, k);
  }
};
