class Solution {
 public:
  int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2},
      dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<vector<double>>> f(
        n, vector<vector<double>>(n, vector<double>(k + 1)));
    for (int st = 0; st <= k; st++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (st == 0)
            f[i][j][st] = 1;
          else {
            for (int d = 0; d < 8; d++) {
              int ni = i + dx[d], nj = j + dy[d];
              if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
              f[i][j][st] += f[ni][nj][st - 1] / 8;
            }
          }
        }
      }
    }
    return f[row][column][k];
  }
};