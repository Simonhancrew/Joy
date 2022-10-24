#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define x first
#define y second
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
class Solution {
 public:
  using PII = pair<int, int>;
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<PII> q;
    vector<vector<int>> dis(n, vector<int>(m, 1e7));
    function<void(int, int)> dfs = [&](int x, int y) {
      q.emplace(x, y);
      dis[x][y] = 0;
      grid[x][y] = 0;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
          dfs(nx, ny);
        }
      }
    };

    auto bfs = [&]() -> int {
      while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = t.x + dx[i], ny = t.y + dy[i];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (grid[nx][ny] == 1) return dis[t.x][t.y];
          if (dis[t.x][t.y] + 1 < dis[nx][ny]) {
            dis[nx][ny] = dis[t.x][t.y] + 1;
            q.emplace(nx, ny);
          }
        }
      }
      return -1;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          dfs(i, j);
          return bfs();
        }
      }
    }
    return -1;
  }
};