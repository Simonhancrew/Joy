class Solution {
 public:
  int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> f(n + 1, vector<int>(3, 0x3f3f3f3f));
    f[0][0] = f[0][2] = 1, f[0][1] = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        if (obstacles[i] == j + 1) continue;
        for (int k = 0; k < 3; k++) {
          if (obstacles[i] == k + 1) continue;
          int t = (k == j ? 0 : 1);
          f[i][j] = min(f[i][j], f[i - 1][k] + t);
        }
      }
    }
    return min(f[n - 1][0], min(f[n - 1][1], f[n - 1][2]));
  }
};