#include <functional>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> p;
  static const int N = 55;
  static const int K = 12;
  static const int MOD = 1e9 + 7;
  int f[K][N][N];
  int query(int a, int b, int c, int d) {
    return p[c][d] - p[a - 1][d] - p[c][b - 1] + p[a - 1][b - 1];
  }

  int ways(vector<string> &pizza, int k) {
    int n = pizza.size(), m = pizza[0].size();
    p.resize(n + 1, vector<int>(m + 1, 0));
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        if (pizza[i - 1][j - 1] == 'A') p[i][j] += 1;
      }
    }

    function<int(int, int, int)> dfs = [&dfs, this, n, m](int k, int x, int y) {
      if (!k) {
        return query(x, y, n, m) > 0 ? 1 : 0;
      }
      if (f[k][x][y] != -1) {
        return f[k][x][y];
      }
      int res = 0;
      for (int i = x + 1; i <= n; i++) {
        if (query(x, y, i - 1, m)) {
          res = (res + dfs(k - 1, i, y)) % MOD;
        }
      }
      for (int i = y + 1; i <= m; i++) {
        if (query(x, y, n, i - 1)) {
          res = (res + dfs(k - 1, x, i)) % MOD;
        }
      }
      return f[k][x][y] = res;
    };
    return dfs(k - 1, 1, 1);
  }
};
