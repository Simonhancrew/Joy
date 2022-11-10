class Solution {
 public:
  using PII = pair<int, int>;
  const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  struct Node {
    int x, y, s;
  };
  static const int N = 31;
  int dist[N][N][1 << 6];
  int shortestPathAllKeys(vector<string>& grid) {
    memset(dist, 0x3f, sizeof dist);
    queue<Node> q;
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '@') {
          dist[i][j][0] = 0;
          q.push({i, j, 0});
        } else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
          cnt++;
        }
      }
    }
    while (q.size()) {
      auto t = q.front();
      q.pop();
      int x = t.x, y = t.y, s = t.s;
      int d = dist[x][y][s];
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (grid[nx][ny] == '#') continue;
        if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
          int ns = s | (1 << (grid[nx][ny] - 'a'));
          if (dist[nx][ny][ns] > d + 1) {
            dist[nx][ny][ns] = d + 1;
            if (ns == (1 << cnt) - 1) return d + 1;
            q.push({nx, ny, ns});
          }
        } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
          if (s & (1 << grid[nx][ny] - 'A')) {
            if (dist[nx][ny][s] > d + 1) {
              dist[nx][ny][s] = d + 1;
              q.push({nx, ny, s});
            }
          }
        } else {
          if (dist[nx][ny][s] > d + 1) {
            dist[nx][ny][s] = d + 1;
            q.push({nx, ny, s});
          }
        }
      }
    }
    return -1;
  }
};