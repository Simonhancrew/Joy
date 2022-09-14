const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
 public:
  vector<vector<int>> g;
  int n, m;
  struct tree {
    int x, y, h;
  };

  int bfs(tree const &from, tree const &to) {
    if (from.x == to.x && from.y == to.y) return 0;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[from.x][from.y] = 0;
    queue<tree> q;
    q.push(from);
    while (q.size()) {
      auto t = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = t.x + dx[i], ny = t.y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!g[nx][ny]) continue;
        if (dist[nx][ny] > dist[t.x][t.y] + 1) {
          dist[nx][ny] = dist[t.x][t.y] + 1;
          if (nx == to.x && ny == to.y) return dist[nx][ny];
          q.push({nx, ny});
        }
      }
    }
    return -1;
  }

  int cutOffTree(vector<vector<int>> &forest) {
    vector<tree> trees;
    g = forest;
    n = forest.size(), m = forest[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (forest[i][j] > 1) trees.push_back({i, j, forest[i][j]});
      }
    }
    sort(trees.begin(), trees.end(),
         [](tree &l, tree &r) { return l.h < r.h; });
    tree from = {0, 0};
    int res = 0;
    for (tree &to : trees) {
      int t = bfs(from, to);
      if (t == -1) return -1;
      res += t;
      from = to;
    }
    return res;
  }
};