#include <vector>

using namespace std;

class Solution {
 public:
  int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    if (n == 2) return arr[0] * arr[1];
    vector<vector<int>> f(n, vector<int>(n, INT_MAX)), mx(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      f[i][i] = 0;
      int cur = arr[i];
      for (int j = i; j < n; j++) {
        cur = max(cur, arr[j]);
        mx[i][j] = cur;
      }
    }
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        for (int k = i; k < j; k++) {
          f[i][j] =
              min(f[i][j], f[i][k] + f[k + 1][j] + mx[i][k] * mx[k + 1][j]);
        }
      }
    }
    return f[0][n - 1];
  }
};
