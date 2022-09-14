class Solution {
 public:
  int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    int n = patience.size();
    vector<vector<int>> g(n);
    for (const auto& edge : edges) {
      g[edge[0]].push_back(edge[1]);
      g[edge[1]].push_back(edge[0]);
    }

    vector<int> d(n, n);
    queue<int> q;
    q.push(0), d[0] = 0;
    while (q.size()) {
      auto t = q.front();
      q.pop();
      for (auto ne : g[t]) {
        if (d[ne] > d[t] + 1) {
          d[ne] = d[t] + 1;
          q.push(ne);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      int c1 = 2 * d[i], c2 = patience[i];
      int cur = c1 <= c2 ? c1 : (c1 - 1) / c2 * c2 + c1;
      ans = max(ans, cur);
    }

    return ans + 1;
  }
};