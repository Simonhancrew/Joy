class Solution {
 public:
  int minCost(vector<vector<int>> &costs) {
    int n = costs.size();
    vector<vector<int>> f(2, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == 0) f[i & 1][j] = min(f[(i - 1) & 1][1], f[(i - 1) & 1][2]);
        if (j == 1) f[i & 1][j] = min(f[(i - 1) & 1][0], f[(i - 1) & 1][2]);
        if (j == 2) f[i & 1][j] = min(f[(i - 1) & 1][0], f[(i - 1) & 1][1]);
        f[i & 1][j] += costs[i - 1][j];
      }
    }
    return min(f[n & 1][0], min(f[n & 1][1], f[n & 1][2]));
  }
};