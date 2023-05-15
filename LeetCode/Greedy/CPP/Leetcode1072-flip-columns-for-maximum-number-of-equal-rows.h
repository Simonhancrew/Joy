class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> mp;
    int ans = 0, n = matrix.size();
    for (int i = 0; i < n; i++) {
      string a;
      for (const auto x : matrix[i]) {
        a += (x ^ matrix[i][0]);
      }
      ans = max(ans, ++mp[a]);
    }
    return ans;
  }
};
