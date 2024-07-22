#include <algorithm>
#include <vector>

using namespace std;

// NOTE: 不能用并查集，因为引爆可能是单向的，是个图论的连通性问题

class Solution {
public:
  using LL = long long;
  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      LL x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        LL dx = x - bombs[j][0];
        LL dy = y - bombs[j][1];
        if (dx * dx + dy * dy <= r * r) {
          g[i].push_back(j);
        }
      }
    }
    vector<int> st(n);
    auto dfs = [&st, &g](auto &&dfs, int x) -> int {
      st[x] = true;
      int cnt = 1;
      for (const auto y : g[x]) {
        if (st[y])
          continue;
        cnt += dfs(dfs, y);
      }
      return cnt;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ranges::fill(st, 0);
      ans = max(ans, dfs(dfs, i));
    }
    return ans;
  }
};
