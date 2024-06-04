#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  using PII = pair<int, int>;
  vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges,
                                             int signalSpeed) {
    int n = edges.size();
    std::vector<std::vector<PII>> g(n + 1);
    for (const auto &e : edges) {
      auto x = e[0], y = e[1], z = e[2];
      g[x].emplace_back(y, z);
      g[y].emplace_back(x, z);
    }
    function<int(int, int, int)> dfs = [&](int x, int fa, int w) {
      int cnt = (w % signalSpeed == 0);
      for (const auto &[y, z] : g[x]) {
        if (y == fa)
          continue;
        cnt += dfs(y, x, w + z);
      }
      return cnt;
    };
    vector<int> ans(n + 1);
    for (int x = 0; x <= n; x++) {
      int sum = 0;
      for (const auto &[y, w] : g[x]) {
        int cur = dfs(y, x, w);
        ans[x] += cur * sum;
        sum += cur;
      }
    }
    return ans;
  }
};
