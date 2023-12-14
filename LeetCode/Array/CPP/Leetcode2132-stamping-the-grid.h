#include <vector>

using namespace std;

// 二维数组前缀和 + 二维数组差分的应用
// 快速判断一个区域能不能放邮票 -> 二维数组一个区域是不是全0 -> 2维数组前缀和
// 快速的给一个区域放上邮票标记 -> 二维数组一个区域快速的加1 -> 2维数组差分

class Solution {
 public:
  template <typename T>
  void add(T &arr, int a, int b, int c, int d, int x) {
    arr[a][b] += x;
    arr[a][d + 1] -= x;
    arr[c + 1][b] -= x;
    arr[c + 1][d + 1] += x;
  }
  bool possibleToStamp(vector<vector<int>> &grid, int stampHeight,
                       int stampWidth) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> s(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + grid[i][j];
      }
    }
    vector<vector<int>> d(m + 2, vector<int>(n + 2));
    for (int i2 = stampHeight; i2 <= m; i2++) {
      for (int j2 = stampWidth; j2 <= n; j2++) {
        int i1 = i2 - stampHeight + 1;
        int j1 = j2 - stampWidth + 1;
        if (s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] + s[i1 - 1][j1 - 1] ==
            0) {
          add(d, i1, j1, i2, j2, 1);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];
        if (grid[i][j] == 0 && d[i + 1][j + 1] == 0) {
          return false;
        }
      }
    }
    return true;
  }
};
