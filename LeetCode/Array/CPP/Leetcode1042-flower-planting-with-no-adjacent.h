class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<vector<int>> g(n);
    for (const auto& p : paths) {
      int x = p[0] - 1, y = p[1] - 1;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      bool st[5]{};
      for (auto j : g[i]) {
        st[ans[j]] = true;
      }
      for (int j = 1; j <= 4; j++) {
        if (!st[j]) {
          ans[i] = j;
          break;
        }
      }
    }
    return ans;
  }
};
