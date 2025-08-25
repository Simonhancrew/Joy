class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    vector<int> res;
    int n = mat.size(), m = mat[0].size();
    for (int k = 0; k < m + n - 1; ++k) {
      auto [min_j, max_j] = make_tuple(max(k - n + 1, 0), min(k, m - 1));
      if (k % 2 == 0) {
        for (int j = min_j; j <= max_j; ++j) {
          res.push_back(mat[k - j][j]);
        }
      } else {
        for (int j = max_j; j >= min_j; j--) {
          res.push_back(mat[k - j][j]);
        }
      }
    }
    return res;
  }
};
