class Solution {
 public:
  using LL = long long;
  LL quick_pow(LL a, LL b) {
    LL res = 1;
    while (b) {
      if (b & 1) res *= a;
      a = a * a;
      b >>= 1;
    }
    return res;
  }
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> ans;
    for (int i = 0, lhs = 0; (lhs = quick_pow(x, i)) <= bound - 1; i++) {
      for (int j = 0, rhs; lhs + (rhs = quick_pow(y, j)) <= bound; j++) {
        ans.insert(lhs + rhs);
        if (y == 1) break;
      }
      if (x == 1) break;
    }
    return {ans.begin(), ans.end()};
  }
};
