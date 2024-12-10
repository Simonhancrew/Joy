class Solution {
 public:
  static constexpr int MOD   = 1e9 + 7;
  using LL                   = long long;
  const vector<int> next[10] = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
  int f[5000][10];
  int dfs(int i, int j) {
    if (i == 0) {
      return 1;
    }
    auto &res = f[i][j];
    if (res) {
      return res;
    }
    for (const auto &ne : next[j]) {
      res = (LL)(res + dfs(i - 1, ne)) % MOD;
    }
    return res;
  }
  int knightDialer(int n) {
    if (n == 1) {
      return 10;
    }
    int res = 0;
    for (int i = 0; i <= 9; i++) {
      res = (LL)(res + dfs(n - 1, i)) % MOD;
    }
    return res;
  }
};
