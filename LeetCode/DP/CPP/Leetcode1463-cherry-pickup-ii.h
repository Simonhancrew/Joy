#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  static constexpr int N = 71;
  int f[N][N][N];
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    memset(f, -1, sizeof(f));
    function<int(int, int, int)> dfs = [&](int i, int j, int k) {
      if (i >= n || j < 0 || j >= m || k >= m || k < 0) {
        return 0;
      }
      int &res = f[i][j][k];
      if (res != -1) {
        return res;
      }
      for (int jj = j - 1; jj <= j + 1; jj++) {
        for (int kk = k - 1; kk <= k + 1; kk++) {
          res = max(res, dfs(i + 1, jj, kk));
        }
      }
      res += grid[i][j] + (k != j ? grid[i][k] : 0);
      return res;
    };
    return dfs(0, 0, m - 1);
  }
};
