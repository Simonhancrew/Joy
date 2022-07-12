class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>> &indices) {
    vector<int> row(m), col(n);
    for (auto pos : indices) {
      int r = pos[0], c = pos[1];
      row[r]++, col[c]++;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (row[i] + col[j] & 1)
          ++cnt;
      }
    }
    return cnt;
  }
};