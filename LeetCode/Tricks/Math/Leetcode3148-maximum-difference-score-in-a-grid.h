#include <algorithm>
#include <vector>

// a->b->c, dis = b - a + c - b = c - a => route doesn't matter, start and end
// point matters
// 每个点找左上角的最小值，取差，左上角的最小值用二维最小前缀维护

using namespace std;

class Solution {
public:
  static constexpr int INF = 2e5 + 10;
  int maxScore(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = -INF;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int mn = min(f[i + 1][j], f[i][j + 1]);
        ans = max(ans, grid[i][j] - mn);
        f[i + 1][j + 1] = min(mn, grid[i][j]);
      }
    }
    return ans;
  }
};
