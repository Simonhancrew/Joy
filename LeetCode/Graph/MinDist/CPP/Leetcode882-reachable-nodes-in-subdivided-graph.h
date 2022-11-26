class Solution {
 public:
  using PII = pair<int, int>;
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    unordered_map<int, vector<PII>> g;
    for (auto& e : edges) {
      int a = e[0], b = e[1], c = e[2];
      g[a].emplace_back(b, c + 1), g[b].emplace_back(a, c + 1);
    }
    vector<int> dist(n, 0x3f3f3f3f);
    auto spfa = [&]() {
      vector<int> st(n, 0);
      queue<int> q;
      dist[0] = 0, q.push(0), st[0] = true;
      while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (auto [p, d] : g[t]) {
          if (dist[p] > dist[t] + d) {
            dist[p] = dist[t] + d;
            if (!st[p]) {
              q.push(p);
              st[p] = true;
            }
          }
        }
      }
    };
    auto dij = [&]() {
      priority_queue<PII, vector<PII>, greater<PII>> q;
      vector<int> st(n);
      q.push({0, 0});
      dist[0] = 0;
      while (q.size()) {
        auto tmp = q.top();
        q.pop();
        int d = tmp.first, t = tmp.second;
        if (st[t]) continue;
        st[t] = 1;
        for (auto& [p, d] : g[t]) {
          if (dist[p] > dist[t] + d) {
            dist[p] = dist[t] + d;
            q.push({dist[p], p});
          }
        }
      }
    };
    dij();
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] <= maxMoves) res++;
    }
    for (auto& e : edges) {
      int a = e[0], b = e[1], c = e[2];
      int x = max(0, maxMoves - dist[a]), y = max(0, maxMoves - dist[b]);
      res += min(x + y, c);
    }
    return res;
  }
};