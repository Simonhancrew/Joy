/*
    方格取数来回版，看作两者从起点同出发。速度是一致的
    如果来回K次的话=>网络流
*/
class Solution {
 public:
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size();
    // f[i][j][k],从(1,1)出发，到达(i,k - i)和(j,k - j)时的最大可摘取数
    vector<vector<vector<int>>> f(
        n + 1, vector<vector<int>>(n + 1, vector<int>(2 * n + 1, INT_MIN)));
    f[1][1][2] = grid[0][0];
    for (int k = 3; k <= 2 * n; k++) {
      for (int i = max(k - n, 1); i <= min(n, k - 1); i++) {
        for (int j = max(1, k - n); j <= min(n, k - 1); j++) {
          if (grid[i - 1][k - i - 1] == -1 || grid[j - 1][k - j - 1] == -1)
            continue;
          int t = grid[i - 1][k - i - 1];
          if (i != j) t += grid[j - 1][k - j - 1];
          for (int a = i - 1; a <= i; a++) {
            for (int b = j - 1; b <= j; b++) {
              f[i][j][k] = max(f[i][j][k], f[a][b][k - 1] + t);
            }
          }
        }
      }
    }
    return max(0, f[n][n][2 * n]);
  }
};