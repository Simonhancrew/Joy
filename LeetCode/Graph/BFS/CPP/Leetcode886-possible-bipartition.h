class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> g(n + 1);
    for (auto pi : dislikes) {
      auto l = pi[0], r = pi[1];
      g[l].push_back(r), g[r].push_back(l);
    }
    vector<int> color(n + 1);
    function<bool(int, int)> dfs = [&](int x, int c) {
      color[x] = c;
      for (int v : g[x]) {
        if (color[v]) {
          if (color[v] == c) return false;
        } else if (!dfs(v, 3 - c)) {
          return false;
        }
      }
      return true;
    };
    for (int i = 1; i <= n; i++) {
      if (!color[i] && !dfs(i, 1)) {
        return false;
      }
    }
    return true;
  }
};