// 区间dp + 前缀和

#if 1
class Solution {
 public:
  enum {
    N = 35,
  };
  int f[N][N][N]{};
  int s[N]{};
  int k{};
  int dfs(int l, int r, int p) {
    auto& res = f[l][r][p];
    if (res != -1) return res;
    if (p == 1) {
      return res = l == r ? 0 : dfs(l, r, k) + s[r + 1] - s[l];
    }
    res = numeric_limits<int>::max();
    for (int i = l; i < r; i += k - 1) {
      res = min(res, dfs(l, i, 1) + dfs(i + 1, r, p - 1));
    }
    return res;
  }
  int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    memset(f, -1, sizeof f);
    this->k = k;
    if ((n - 1) % (k - 1)) return -1;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + stones[i - 1];
    return dfs(0, n - 1, 1);
  }
};
#else
class Solution {
 public:
  enum {
    N = 35,
  };
  int f[N][N];
  int s[N];
  int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    if ((n - 1) % (k - 1)) return -1;
    memset(f, 0x3f, sizeof f);
    memset(s, 0, sizeof s);

    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + stones[i - 1];
      f[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        for (int u = i; u < j; u += k - 1) {
          f[i][j] = min(f[i][j], f[i][u] + f[u + 1][j]);
        }
        if ((len - 1) % (k - 1) == 0) {
          f[i][j] += s[j] - s[i - 1];
        }
      }
    }
    return f[1][n];
  }
};

#endif
