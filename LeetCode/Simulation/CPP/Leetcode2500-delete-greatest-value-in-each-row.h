#include <algorithm>
#include <vector>


using namespace std;

class Solution {
 public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    for (auto& x : grid) {
      sort(x.begin(), x.end());
    }
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < m; i++) {
      int cur = INT_MIN;
      for (int j = 0; j < n; j++) {
        cur = max(cur, grid[j][i]);
      }
      ans += cur;
    }
    return ans;
  }
};
