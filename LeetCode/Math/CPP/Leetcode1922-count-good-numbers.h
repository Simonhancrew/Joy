class Solution {
 public:
  using LL                 = long long;
  static constexpr int MOD = 1e9 + 7;
  LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
      if (b & 1) {
        res = res * a % MOD;
      }
      a = (a * a) % MOD;
      b >>= 1;
    }
    return res;
  }

  int countGoodNumbers(long long n) {
    return qpow(5, (n + 1) / 2) * qpow(4, n / 2) % MOD;
  }
};
