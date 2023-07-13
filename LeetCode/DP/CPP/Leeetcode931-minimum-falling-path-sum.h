#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int dx[3] = {-1, -1, -1};
  static constexpr int dy[3] = {-1, 0, 1};
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> f(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) f[0][i] = matrix[0][i];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 3; k++) {
          auto nx = i + dx[k], ny = j + dy[k];
          if (nx < 0 || ny < 0 || ny >= n) continue;
          f[i][j] = min(f[i][j], f[nx][ny] + matrix[i][j]);
        }
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) ans = min(ans, f[n - 1][i]);
    return ans;
  }
};
