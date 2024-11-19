class Solution {
 public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    vector<int> ans;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      g[i].push_back(i + 1);
    }
    auto bfs = [&g, n]() {
      queue<int> q;
      q.push(0);
      vector<int> st(n, false);
      int res = 0;
      while (!q.empty()) {
        int tot = q.size();
        for (int i = 0; i < tot; i++) {
          auto t = q.front();
          st[t]  = true;
          q.pop();
          for (const auto ne : g[t]) {
            if (ne == n - 1)
              return res + 1;
            if (!st[ne])
              q.push(ne);
          }
        }
        res++;
      }
      return res;
    };
    ans.reserve(queries.size());
    for (const auto &q : queries) {
      g[q[0]].push_back(q[1]);
      ans.push_back(bfs());
    }
    return ans;
  }
};
