class Solution {
 public:
  using PII = pair<int, int>;
  int n{};
  PII get(int x) { return {x / n, x % n}; }
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
    vector<vector<int>> dis(n, vector<int>(n, 1e4));
    dis[0][0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      auto [x, y] = get(q.front());
      q.pop();
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          if (i == 0 && j == 0) continue;
          auto nx = x + i, ny = y + j;
          if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if (grid[nx][ny] != 0) continue;
          if (dis[nx][ny] > dis[x][y] + 1) {
            dis[nx][ny] = dis[x][y] + 1;
            q.push(nx * n + ny);
          }
        }
      }
    }
    return dis[n - 1][n - 1] == 1e4 ? -1 : dis[n - 1][n - 1];
  }
};

