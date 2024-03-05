#include <queue>
#include <vector>


using namespace std;

class Solution {
public:
  static constexpr int MOD = 1e9 + 7;
  static constexpr int INF = 0x3f3f3f3f;
  using PII = pair<int, int64_t>;
  using LL = int64_t;
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<PII>> g(n);
    vector<int> f(n, 0);
    f[0] = 1;
    for (const auto &r : roads) {
      auto a = r[0], b = r[1], d = r[2];
      g[a].emplace_back(b, d);
      g[b].emplace_back(a, d);
    }
    auto cmp = [](PII &lhs, PII &rhs) { return lhs.second > rhs.second; };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    vector<LL> dis(n, numeric_limits<int64_t>::max());
    dis[0] = 0;
    heap.emplace(0, 0);
    while (!heap.empty()) {
      auto [x, d] = heap.top();
      heap.pop();
      if (x == n - 1) {
        return f[n - 1];
      }
      if (d > dis[x])
        continue;
      for (const auto &[y, val] : g[x]) {
        if (d + val < dis[y]) {
          dis[y] = d + val;
          f[y] = f[x];
          heap.emplace(y, dis[y]);
          continue;
        }
        if (d + val == dis[y]) {
          f[y] = (f[y] + f[x]) % MOD;
          continue;
        }
      }
    }
    return f[n - 1];
  }
};
