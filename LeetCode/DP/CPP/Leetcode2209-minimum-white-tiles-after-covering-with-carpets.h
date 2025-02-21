class Solution {
 public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    vector<vector<int>> f(numCarpets + 1, vector<int>(floor.size(), -1));
    auto dfs = [&](auto &&dfs, int i, int j) {
      if (j < i * carpetLen) {
        return 0;
      }
      auto &res = f[i][j];
      if (res != -1) {
        return res;
      }
      if (i == 0) {
        return res = dfs(dfs, i, j - 1) + (floor[j] - '0');
      }
      return res = min(dfs(dfs, i, j - 1) + (floor[j] - '0'),
                       dfs(dfs, i - 1, j - carpetLen));
    };
    return dfs(dfs, numCarpets, floor.size() - 1);
  }
};
