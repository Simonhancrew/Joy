#include <functional>
#include <vector>


using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> f(n, vector<int>(amount + 1, -1));
    function<int(int, int)> dfs = [&](int i, int c) {
      if (i < 0)
        return c == 0 ? 0 : INT_MAX / 2;
      auto &res = f[i][c];
      if (res != -1)
        return res;
      if (c < coins[i])
        return res = dfs(i - 1, c);
      return res = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
    };
    auto res = dfs(n - 1, amount);
    return res < INT_MAX / 2 ? res : -1;
  }
};
