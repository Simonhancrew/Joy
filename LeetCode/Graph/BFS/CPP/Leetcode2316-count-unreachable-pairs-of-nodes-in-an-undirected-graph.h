#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> st(n, 0);
    int tot = n;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
      if (st[i] == 1) continue;
      st[i] = 1;
      queue<int> q;
      q.push(i);
      int sz = 1;
      while (q.size()) {
        auto t = q.front();
        q.pop();
        for (const auto x : g[t]) {
          if (st[x] == 1) continue;
          q.push(x);
          st[x] = 1;
          sz++;
        }
      }
      ans += (LL)sz * (tot - sz);
      tot -= sz;
    }
    return ans;
  }
};
