class Solution {
 public:
  int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> f(n, vector<int>(n, 0));
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        if (len == 3)
          f[i][j] = values[i] * values[j] * values[i + 1];
        else {
          f[i][j] = INT_MAX;
          for (int k = i + 1; k < j; k++) {
            f[i][j] = min({f[i][j], f[i][k] + f[k][j] +
                                        values[i] * values[k] * values[j]});
          }
        }
      }
    }
    return f[0][n - 1];
  }
};