#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int INF = 0x3f3f3f3f;
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> f(n, vector<int>(m, INF));
    for (int i = 0; i < m; i++) f[0][i] = grid[0][i];
    for (int i = 1; i < n; i++) {
      for (int k = 0; k < m; k++) {
        for (int j = 0; j < m; j++) {
          f[i][j] = min(f[i][j],
                        f[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
        }
      }
    }
    int ans = INF;
    for (int i = 0; i < m; i++) ans = min(ans, f[n - 1][i]);
    return ans;
  }
};
