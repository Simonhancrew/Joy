#include <vector>
#include <functional>

using namespace std;

class Solution {
 public:
  static const int MOD = 1e9 + 7;
  using LL = long long;
  int numRollsToTarget(int n, int k, int target) {
    vector<vector<LL>> f(n, vector<LL>(target, -1ll));
    function<LL(int, int)> dfs = [&dfs, &f, n, k, target](int id, int sum) {
      if (n <= id) {
        if (sum == target) return 1ll;
        return 0ll;
      }
      if (f[id][sum] != -1) {
        return f[id][sum];
      }
      f[id][sum] = 0;
      for (int i = k; i >= 1; i--) {
        auto cur = sum + i;
        if (cur > target || cur + n - id - 1 > target ||
            cur + k * (n - id - 1) < target)
          continue;
        f[id][sum] = (f[id][sum] + dfs(id + 1, cur)) % MOD;
      }
      return f[id][sum];
    };
    return dfs(0, 0);
  }
};
