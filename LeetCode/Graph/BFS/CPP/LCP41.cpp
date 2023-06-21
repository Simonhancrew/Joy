#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  static constexpr int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
  static constexpr int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

  bool check(const vector<string>& g, int x, int y, int dx, int dy) {
    x += dx;
    y += dy;
    while (0 <= x && x < g.size() && 0 <= y && y < g[0].size()) {
      if (g[x][y] == 'X') {
        return true;
      } else if (g[x][y] == '.') {
        return false;
      }
      x += dx;
      y += dy;
    }
    return false;
  }

  int get(vector<string> g, int sx, int sy) {
    queue<PII> q;
    q.emplace(sx, sy);
    g[sx][sy] = 'X';
    int res = 0;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t.first, y = t.second;
      for (int i = 0; i < 8; i++) {
        if (check(g, x, y, dx[i], dy[i])) {
          int nx = x + dx[i], ny = y + dy[i];
          while (g[nx][ny] != 'X') {
            q.emplace(nx, ny);
            g[nx][ny] = 'X';
            nx += dx[i];
            ny += dy[i];
            ++res;
          }
        }
      }
    }
    return res;
  }

  int flipChess(vector<string>& chessboard) {
    int ans = 0;
    int n = chessboard.size(), m = chessboard[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (chessboard[i][j] == '.') {
          ans = max(ans, get(chessboard, i, j));
        }
      }
    }
    return ans;
  }
};
