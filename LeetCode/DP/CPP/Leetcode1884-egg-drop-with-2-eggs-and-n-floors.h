class Solution {
public:
  static const int N = 1e3 + 10;
  int f[N]{};
  int twoEggDrop(int n) {
    if (n == 0) {
      return 0;
    }
    auto &res = f[n];
    if (res) {
      return res;
    }
    res = INT_MAX;
    for (int j = 1; j <= n; j++) {
      res = min(res, max(j, twoEggDrop(n - j) + 1));
    }
    return res;
  }
};
