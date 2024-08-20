class Solution {
public:
  using LL = long long;
  int waysToReachStair(int k) {
    unordered_map<LL, int> f;
    auto dfs = [&](auto &&dfs, int i, int j, bool pre) {
      if (i > k + 1) {
        return 0;
      }
      auto key = ((LL)i << 32) | j << 1 | pre;
      if (f.contains(key)) {
        return f[key];
      }
      int res = i == k;
      res += dfs(dfs, i + (1 << j), j + 1, false);
      if (i && !pre) {
        res += dfs(dfs, i - 1, j, true);
      }
      return f[key] = res;
    };
    return dfs(dfs, 1, 0, 0);
  }
};
