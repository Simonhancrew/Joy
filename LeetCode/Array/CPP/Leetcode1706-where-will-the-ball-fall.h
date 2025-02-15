class Solution {
 public:
  vector<int> findBall(vector<vector<int>> &grid) {
    int n = grid[0].size();
    vector<int> res(n, -1);
    for (int j = 0; j < n; ++j) {
      int col = j;
      for (const auto &row : grid) {
        int d = row[col];
        col += d;
        if (col < 0 || col == n || d != row[col]) {
          col = -1;
          break;
        }
      }
      res[j] = col;
    }
    return res;
  }
};
