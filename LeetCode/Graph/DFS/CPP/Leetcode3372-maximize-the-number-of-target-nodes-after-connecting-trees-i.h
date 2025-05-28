class Solution {
 public:
  static auto build(vector<vector<int>> edges) {
    vector<vector<int>> g(edges.size() + 1, vector<int>{});
    for (const auto &e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    return g;
  }
  static int dfs(int x, int fa, vector<vector<int>> &g, int d, int k) {
    if (d > k) {
      return 0;
    }
    int cnt = 1;
    for (auto ne : g[x]) {
      if (ne == fa)
        continue;
      cnt += dfs(ne, x, g, d + 1, k);
    }
    return cnt;
  }
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<vector<int>> g1 = build(edges1), g2 = build(edges2);
    vector<int> ans(n);
    int mx2 = 0;
    for (int i = 0; i < m; i++) {
      mx2 = max(mx2, dfs(i, -1, g2, 0, k - 1));
    }
    for (int i = 0; i < n; i++) {
      ans[i] = mx2 + dfs(i, -1, g1, 0, k);
    }
    return ans;
  }
};
