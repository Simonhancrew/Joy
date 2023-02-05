class Solution {
 public:
  struct Node {
    int x, y, d;
  };
  int dx[2] = {0, 1}, dy[2] = {1, 0};
  enum {
    N = 110,
    INF = 0x3f3f3f3f,
  };
  int dist[N][N][2];
  queue<Node> q;
  void update(int x, int y, int d, int dis) {
    if (dist[x][y][d] > dis) {
      dist[x][y][d] = dis;
      q.push({x, y, d});
    }
  }

  int minimumMoves(vector<vector<int>>& grid) {
    memset(dist, 0x3f, sizeof dist);
    q.push({0, 0, 0});
    dist[0][0][0] = 0;
    int n = grid.size();
    while (q.size()) {
      auto t = q.front();
      q.pop();
      int dis = dist[t.x][t.y][t.d];
      if (t.x == n - 1 && t.y == n - 2 && t.d == 0) {
        return dis;
      }
      Node a = {t.x, t.y}, b = {t.x + dx[t.d], t.y + dy[t.d]};
      // right
      if (a.y + 1 < n && !grid[a.x][a.y + 1] && b.y + 1 < n && !grid[b.x][b.y + 1]) {
        update(a.x, a.y + 1, t.d, dis + 1);
      }
      // down
      if (a.x + 1 < n && !grid[a.x + 1][a.y] && b.x + 1 < n && !grid[b.x + 1][b.y]) {
        update(a.x + 1, a.y, t.d, dis + 1);
      }
      // 90顺
      if (t.d == 0 && t.x + 1 < n && !grid[t.x + 1][t.y] && !grid[b.x + 1][b.y]) {
        update(t.x, t.y, 1, dis + 1);
      }
      // 90逆
      if (t.d == 1 && t.y + 1 < n && !grid[t.x][t.y + 1] && !grid[t.x + 1][t.y + 1]) {
        update(t.x, t.y, 0, dis + 1);
      }
    }
    return -1;
  }
};