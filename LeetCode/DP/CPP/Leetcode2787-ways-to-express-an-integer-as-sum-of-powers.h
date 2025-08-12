class Solution {
 public:
  int qpow(int a, int b) {
    int res = 1;
    while (b) {
      if (b & 1)
        res *= a;
      a = (a * a);
      b >>= 1;
    }
    return res;
  }
  using LL                 = long long;
  static constexpr int MOD = 1e9 + 7;
  int numberOfWays(int n, int x) {
    vector f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; qpow(i, x) <= n; i++) {
      int cur = qpow(i, x);
      for (int j = n; j >= cur; j--) {
        f[j] = ((LL)f[j] + f[j - cur]) % MOD;
      }
    }
    return f[n] % MOD;
  }
};
