class Solution {
 public:
  using LL = long long;
  const int MOD = 1e9 + 7;

  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

  LL get(LL tar, int a, int b) { return tar / a + tar / b - tar / (a * b / gcd(a, b)); }

  int nthMagicalNumber(int n, int a, int b) {
    LL l = 0, r = 4e13;
    while (l < r) {
      LL mid = l + r >> 1;
      if (get(mid, a, b) >= n)
        r = mid;
      else
        l = mid + 1;
    }
    return l % MOD;
  }
};