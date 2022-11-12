// 蒙德里安猜想的简化版，不用状压dp
// f[i][j]，填完前i列，第i + 1列的状态是j
// 因为只有两行，所以状态很少，做一个状态转移的硬推w
class Solution {
 public:
  const int P = 1e9 + 7;
  int numTilings(int n) {
    int w[4][4] = {{1, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 0, 1}, {1, 0, 0, 0}};
    vector<vector<int>> f(n + 1, vector<int>(4, 0));
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          f[i + 1][k] = (f[i + 1][k] + f[i][j] * w[j][k]) % P;
        }
      }
    }
    return f[n][0];
  }
};