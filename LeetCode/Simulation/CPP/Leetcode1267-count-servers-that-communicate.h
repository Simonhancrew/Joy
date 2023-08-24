#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  int countServers(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    set<pair<int, int>> st;
    int ans = 0;
    auto check = [&](int x, int y) {
      if (st.count({x, y})) return true;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (grid[nx][ny] == 1) {
            st.insert({nx, ny});
            return true;
          }
          nx = nx + dx[i];
          ny = ny + dy[i];
        }
      }
      return false;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          if (check(i, j)) ans++;
        }
      }
    }
    return ans;
  }
};
