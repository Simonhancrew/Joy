class Solution {
public:
  int minCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    int m = cuts.size();
    ranges::sort(cuts);
    vector<vector<int>> f(m, vector<int>(m, -1));
    auto dfs = [&](auto &&dfs, int l, int r) {
      if (l + 1 == r) {
        return 0;
      }
      auto &res = f[l][r];
      if (res != -1) {
        return res;
      }
      res = INT_MAX;
      for (int mid = l + 1; mid < r; ++mid) {
        res = min(res, dfs(dfs, l, mid) + dfs(dfs, mid, r));
      }
      res += cuts[r] - cuts[l];
      return res;
    };
    return dfs(dfs, 0, m - 1);
  }
};
