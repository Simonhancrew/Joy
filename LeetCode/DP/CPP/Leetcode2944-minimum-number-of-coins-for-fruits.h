#include <iostream>

using namespace std;

class Solution {
 public:
  int minimumCoins(vector<int>& prices) {
    int n = prices.size();
    vector<int> f((n + 1) / 2);
    auto dfs = [&](auto&& dfs, int i) {
      if (i * 2 >= n) {
        return prices[i - 1];
      }
      auto& res = f[i];
      if (res) {
        return res;
      }
      res = INT_MAX;
      for (int j = i + 1; j <= 2 * i + 1; j++) {
        res = min(res, dfs(dfs, j));
      }
      res += prices[i - 1];
      return res;
    };
    return dfs(dfs, 1);
  }
};

