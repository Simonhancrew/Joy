#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<vector<int>> f(n, vector<int>(amount + 1, -1));
    function<int(int, int)> dfs = [&](int idx, int val) {
      if (idx < 0) {
        return val == 0 ? 1 : 0;
      }
      auto &res = f[idx][val];
      if (res != -1) {
        return res;
      }
      if (val < coins[idx]) {
        return res = dfs(idx - 1, val);
      }
      return res = dfs(idx - 1, val) + dfs(idx, val - coins[idx]);
    };
    return dfs(n - 1, amount);
  }
};
