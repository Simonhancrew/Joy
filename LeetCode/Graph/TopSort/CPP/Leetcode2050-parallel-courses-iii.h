#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> g(n + 1);
    vector<int> in(n + 1);
    for (const auto& x : relations) {
      g[x[0]].push_back(x[1]);
      in[x[1]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0) q.push(i);
    }
    vector<int> f(n + 1, 0);
    int ans = 0;
    while (q.size()) {
      auto tot = q.size();
      for (int i = 0; i < tot; i++) {
        auto t = q.front();
        q.pop();
        auto cost = time[t - 1];
        f[t] += cost;
        ans = max(ans, f[t]);
        // cout << ans << endl;
        for (const auto ne : g[t]) {
          f[ne] = max(f[ne], f[t]);
          in[ne]--;
          if (in[ne] == 0) {
            q.push(ne);
          }
        }
      }
    }
    return ans;
  }
};
