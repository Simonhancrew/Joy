#include <vector>
#include <functional>

using namespace std;

// 考虑每个点的下车人，然后让这个值最大就可以了
// 前一个下车位置的最大收益 + 这个点的收益-> f[x - 1] + max(x)

class Solution {
 public:
  using LL = long long;
  using PII = pair<int, int>;
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<vector<PII>> s(n + 1);
    for (const auto p : rides) {
      auto x = p[0], y = p[1], t = p[2];
      s[y].emplace_back(x, y - x + t);
    }
    vector<LL> f(n + 1, -1);
    function<LL(int)> dfs = [&](int x) {
      if (x == 1) {
        return 0ll;
      }
      auto& res = f[x];
      if (res != -1) {
        return res;
      }
      res = dfs(x - 1);
      for (const auto& [p, t] : s[x]) {
        res = max(res, dfs(p) + t);
      }
      return res;
    };
    return dfs(n);
  }
};
