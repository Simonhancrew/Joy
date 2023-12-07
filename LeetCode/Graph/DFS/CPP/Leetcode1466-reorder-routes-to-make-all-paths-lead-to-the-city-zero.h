#include <vector>
#include <functional>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<PII>> g(n);
    for (const auto p : connections) {
      auto x = p[0], y = p[1];
      g[x].emplace_back(y, 1);
      g[y].emplace_back(x, 0);
    }
    int ans = 0;
    function<void(int, int)> dfs = [&](int x, int fa) {
      for (const auto& [y, d] : g[x]) {
        if (y == fa) continue;
        if (d == 1) ans++;
        dfs(y, x);
      }
    };
    dfs(0, -1);
    return ans;
  }
};
