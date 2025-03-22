class Solution {
 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      int cur = reduce(mat[i].begin(), mat[i].end());
      if (cur > cnt) {
        ans = i;
        cnt = cur;
      }
    }
    return {ans, cnt};
  }
};