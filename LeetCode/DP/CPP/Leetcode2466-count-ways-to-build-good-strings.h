class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  using LL                 = long long;
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> f(high + 1, -1);
    auto dfs = [&](this auto &&dfs, int i) {
      if (i > high) {
        return 0;
      }
      if (f[i] != -1) {
        return f[i];
      }
      int &res = f[i];
      res      = 0;
      if (i + one <= high) {
        auto add = (i + one >= low) ? 1 : 0;
        res      = (LL)(res + add + dfs(i + one)) % MOD;
      }
      if (i + zero <= high) {
        auto add = (i + zero >= low) ? 1 : 0;
        res      = (LL)(res + add + dfs(i + zero)) % MOD;
      }
      return res;
    };
    return dfs(0);
  }
};
