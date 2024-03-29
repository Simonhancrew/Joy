class Solution {
 public:
  vector<int> f;
  int n, m;
  int dp(int x) {
    if (f[x] != -1) return f[x];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (x >> i & 1) {
        sum += i + 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (x >> i & 1) continue;
      if (sum + i + 1 >= m) return f[x] = 1;
      if (!dp(x + (1 << i))) return f[x] = 1;
    }
    return f[x] = 0;
  }

  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    n = maxChoosableInteger, m = desiredTotal;
    if ((n + 1) * n / 2 < m) return false;
    f.resize(1 << n, -1);
    return dp(0);
  }
};