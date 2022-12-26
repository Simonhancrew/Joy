// simple simulation
class Solution {
 public:
  const int MOD = 1e9 + 7;
  using LL = long long;
  int countHomogenous(string s) {
    int res = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && s[j] == s[i]) j++;
      int d = j - i;
      res += ((LL)(d + 1) * d / 2) % MOD;
      i = j - 1;
    }
    return res;
  }
};