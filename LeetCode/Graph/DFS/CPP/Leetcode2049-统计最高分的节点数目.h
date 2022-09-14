class Solution {
 public:
  typedef long long LL;
  vector<vector<int>> g;
  int cnt = 0, n;
  LL mx = 0;
  vector<int> sz;
  int countHighestScoreNodes(vector<int> &parents) {
    n = parents.size();
    g.resize(n), sz.resize(n);
    for (int i = 1; i < n; i++) {
      g[parents[i]].push_back(i);
    }
    dfs(0);
    return cnt;
  }
  void dfs(int u) {
    sz[u] = 1;
    LL tmp = 1;
    for (auto s : g[u]) {
      dfs(s);
      sz[u] += sz[s];
      tmp *= sz[s];
    }
    if (n - sz[u]) tmp *= n - sz[u];
    if (tmp > mx) {
      cnt = 1;
      mx = tmp;
    } else if (tmp == mx) {
      cnt++;
    }
  }
};