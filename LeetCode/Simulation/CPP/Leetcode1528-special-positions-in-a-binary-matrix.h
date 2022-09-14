class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int ans = 0;
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        r[i] += mat[i][j], c[j] += mat[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 1 && c[j] == 1 && r[i] == 1) ++ans;
      }
    }
    return ans;
  }
};