class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    int n = piles.size();
    vector<vector<int>> f(n, vector<int>(k + 1));
    auto dfs = [&](auto &&dfs, int i, int j) {
      if (i < 0) {
        return 0;
      }
      auto &res = f[i][j];
      if (res) {
        return res;
      }
      res   = dfs(dfs, i - 1, j);
      int v = 0;
      for (int w = 0; w < j && w < piles[i].size(); ++w) {
        v += piles[i][w];
        res = max(res, dfs(dfs, i - 1, j - w - 1) + v);
      }
      return res;
    };
    return dfs(dfs, n - 1, k);
  }
};
