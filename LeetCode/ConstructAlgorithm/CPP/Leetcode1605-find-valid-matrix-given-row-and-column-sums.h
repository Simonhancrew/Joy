class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int n = rowSum.size(), m = colSum.size();
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int cur = min(rowSum[i], colSum[j]);
        res[i][j] = cur;
        rowSum[i] -= cur;
        colSum[j] -= cur;
      }
    }
    return res;
  }
};
