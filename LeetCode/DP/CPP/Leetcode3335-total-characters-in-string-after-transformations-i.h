class Solution {
 public:
  using LL             = long long;
  static const int MOD = 1e9 + 7;
  int lengthAfterTransformations(string s, int t) {
    array<LL, 26> cnt{};
    for (const auto c : s) {
      cnt[c - 'a']++;
    }
    for (int i = 0; i < t; i++) {
      array<LL, 26> tmp{};
      for (int j = 0; j < 25; j++) {
        tmp[j + 1] = cnt[j];
      }
      tmp[0] = cnt[25];
      tmp[1] = (tmp[1] + cnt[25]) % MOD;
      cnt    = tmp;
    }
    int ans = 0;
    for (const auto x : cnt) {
      ans = (ans + x) % MOD;
    }
    return ans;
  }
};
