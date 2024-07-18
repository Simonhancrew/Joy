#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  using PII = pair<int, int>;
  static vector<int> minimumTime(int n, vector<vector<int>> &edges,
                          vector<int> &disappear) {
    vector<vector<PII>> g(n);
    for (const auto &e : edges) {
      g[e[0]].emplace_back(e[1], e[2]);
      g[e[1]].emplace_back(e[0], e[2]);
    }
    vector<int> d(n, 0x3f3f3f3f);
    d[0] = 0;
    priority_queue<PII, vector<PII>, greater<>> q;
    q.emplace(0, 0);
    vector<int> ans(n, -1);
    while (!q.empty()) {
      auto t = q.top();
      q.pop();
      int u = t.second;
      int dis = t.first;
      if (d[u] < dis)
        continue;
      ans[u] = d[u];
      for (const auto &v : g[u]) {
        if (d[v.first] > d[u] + v.second &&
            d[u] + v.second < disappear[v.first]) {
          d[v.first] = d[u] + v.second;
          q.emplace(d[v.first], v.first);
        }
      }
    }
    return ans;
  }
};
