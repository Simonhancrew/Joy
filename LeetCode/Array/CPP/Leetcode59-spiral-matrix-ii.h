class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  vector<vector<int>> generateMatrix(int n) {
    int d = 0;
    int x = 0, y = 0;
    int cur = 1;
    vector<vector<int>> res(n, vector<int>(n));
    while (true) {
      if (x < 0 || x >= n || y < 0 || y >= n || res[x][y] != 0) {
        break;
      }
      res[x][y] = cur++;
      int nx    = x + dx[d];
      int ny    = y + dy[d];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n || res[nx][ny] != 0) {
        d  = (d + 1) % 4;
        nx = x + dx[d];
        ny = y + dy[d];
      }
      x = nx;
      y = ny;
    }
    return res;
  }
};
