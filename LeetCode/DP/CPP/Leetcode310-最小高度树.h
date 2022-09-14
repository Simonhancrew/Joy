class Solution {
 public:
  vector<vector<int>> g;
  vector<int> d1, d2, up, p1;

  void dfs1(int u, int fa) {
    for (auto x : g[u]) {
      if (x == fa) continue;
      dfs1(x, u);
      int d = d1[x] + 1;
      if (d >= d1[u]) {
        d2[u] = d1[u], d1[u] = d;
        p1[u] = x;
      } else if (d > d2[u]) {
        d2[u] = d;
      }
    }
  }

  void dfs2(int u, int fa) {
    for (auto x : g[u]) {
      if (x == fa) continue;
      if (p1[u] == x)
        up[x] = max(up[u], d2[u]) + 1;
      else
        up[x] = max(up[u], d1[u]) + 1;
      dfs2(x, u);
    }
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    g.resize(n);
    d1 = up = p1 = d2 = vector<int>(n, 0);
    for (auto &ed : edges) {
      int a = ed[0], b = ed[1];
      g[a].push_back(b), g[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    int mind = n + 1;
    vector<int> res;
    for (int i = 0; i < n; i++) mind = min(mind, max(up[i], d1[i]));
    for (int i = 0; i < n; i++) {
      if (max(up[i], d1[i]) == mind) res.push_back(i);
    }
    return res;
  }
};