class Solution {
public:
  vector<int> fa;
  int find(int x) {
    if (fa[x] != x)
      fa[x] = find(fa[x]);
    return fa[x];
  }

  void merge(int x, int y) {
    auto fx = find(x);
    auto fy = find(y);
    if (fx != fy) {
      fa[fx] = fa[fy];
    }
  }

  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    fa.resize(n + 1);
    iota(fa.begin(), fa.end(), 0);
    for (const auto &e : edges) {
      auto x = e[0], y = e[1];
      if (find(x) == find(y)) {
        return e;
      }
      merge(x, y);
    }
    return {};
  }
};
