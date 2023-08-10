#include <vector>

using namespace std;

// 其实只要知道上一行的最小和次小列就可以了，记录一下这两个值，不用枚举一整列

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> f(2, vector<int>(n, INT_MAX));
    int ans = INT_MAX;
    int p1 = 0, p2 = 0;
    f[0] = grid[0];
    for (int i = 0; i < n; i++) {
      if (f[0][i] < f[0][p1]) {
        p2 = p1;
        p1 = i;
      } else if (f[0][i] < f[0][p2]) {
        p2 = i;
      }
    }
    for (int i = 1; i < n; i++) {
      int cp1 = 0, cp2 = 0;
      for (int j = 0; j < n; j++) {
        f[i % 2][j] = INT_MAX;
        if (p1 == j) {
          f[i % 2][j] = f[(i - 1) % 2][p2] + grid[i][j];
        } else {
          f[i % 2][j] = f[(i - 1) % 2][p1] + grid[i][j];
        }
        if (f[i % 2][j] < f[i % 2][cp1]) {
          cp2 = cp1;
          cp1 = j;
        } else if (f[i % 2][j] < f[i % 2][cp2]) {
          cp2 = j;
        }
      }
      p1 = cp1, p2 = cp2;
      ans = p1;
    }
    return ans;
  }
};

#if 0
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> f(2, vector<int>(n, INT_MAX));
    int ans = INT_MAX;
    int p1 = -1, p2 = -1;
    f[0] = grid[0];
    for (int i = 0; i < n; i++) {
      if (p1 == -1 || f[0][i] < f[0][p1]) {
        p2 = p1;
        p1 = i;
      } else if (p2 == -1 || f[0][i] < f[0][p2]) {
        p2 = i;
      }
    }
    if (n == 1) {
        return f[0][p1];
    }
    cout << f[0][p1] << ' ' << f[0][p2] << endl;
    for (int i = 1; i < n; i++) {
      int cp1 = -1, cp2 = -1;
      for (int j = 0; j < n; j++) {
        f[i % 2][j] = INT_MAX;
        if (p1 == j) {
          f[i % 2][j] = f[(i - 1) % 2][p2] + grid[i][j];
        } else {
          f[i % 2][j] = f[(i - 1) % 2][p1] + grid[i][j];
        }
        if (cp1 == -1 || f[i % 2][j] < f[i % 2][cp1]) {
          cp2 = cp1;
          cp1 = j;
        } else if (cp2 == -1 || f[i % 2][j] < f[i % 2][cp2]) {
          cp2 = j;
        }
      }
      p1 = cp1, p2 = cp2;
      ans = f[i % 2][p1];
    }
    return ans;
  }
};

#endif
