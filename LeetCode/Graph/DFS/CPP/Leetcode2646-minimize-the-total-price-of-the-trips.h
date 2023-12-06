#include <vector>
#include <functional>

using namespace std;

class Solution {
 public:
  int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                        vector<vector<int>>& trips) {
    vector<int> cnt(n);
    vector<vector<int>> g(n);
    for (const auto& p : edges) {
      auto x = p[0], y = p[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }
    function<bool(int, int, int)> dfs = [&](int x, int end, int fa) {
      if (x == end) {
        cnt[x]++;
        return true;
      }
      for (const auto y : g[x]) {
        if (y != fa && dfs(y, end, x)) {
          cnt[x]++;
          return true;
        }
      }
      return false;
    };
    for (const auto& p : trips) {
      auto x = p[0], end = p[1];
      dfs(x, end, -1);
    }
    using PII = pair<int, int>;
    function<PII(int, int)> f = [&](int x, int fa) -> PII {
      int tot = cnt[x] * price[x];
      int half_tot = tot / 2;
      for (const auto y : g[x]) {
        if (y != fa) {
          PII res = f(y, x);
          tot += min(res.second, res.first);
          half_tot += res.first;
        }
      }
      return {tot, half_tot};
    };
    auto res = f(0, -1);
    return min(res.first, res.second);
  }
};
