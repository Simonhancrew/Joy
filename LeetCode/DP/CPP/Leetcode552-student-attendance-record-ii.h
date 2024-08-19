constexpr int N = 1e5 + 10;
constexpr int MOD = 1e9 + 7;
int f[N][2][3];

class Solution {
public:
  int dfs(int i, int j, int k) {
    if (i == 0) {
      return 1;
    }
    auto &res = f[i][j][k];
    if (res != 0) {
      return res;
    }
    res = dfs(i - 1, j, 0);
    if (j == 0) {
      res = (res + dfs(i - 1, 1, 0)) % MOD;
    }
    if (k < 2) {
      res = (res + dfs(i - 1, j, k + 1)) % MOD;
    }
    return res;
  }
  int checkRecord(int n) { return dfs(n, 0, 0); }
};
