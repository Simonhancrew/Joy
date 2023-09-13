#include <queue>

using namespace std;

class Solution {
 public:
  const int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
  const int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
  size_t n = 0;
  int get(int x, int y) const { return x * n + y; }
  bool checkValidGrid(vector<vector<int>>& grid) {
    n = grid.size();
    queue<int> q;
    q.push(0);
    int cnt = 0;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t / n, y = t % n;
      cnt++;
      int ne = grid[x][y];
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (ne + 1 != grid[nx][ny]) continue;
        q.push(get(nx, ny));
        break;
      }
    }
    return cnt == n * n;
  }
};
