#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int INF = 0x3f3f3f3f;
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> f(2, vector<int>(2));
    f[0][1] = -INF, f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      f[i & 1][0] = max(f[i - 1 & 1][0], f[i - 1 & 1][1] + prices[i - 1]);
      f[i & 1][1] = max(f[i - 1 & 1][1], f[i - 1 & 1][0] - prices[i - 1] - fee);
    }
    return f[n & 1][0];
  }
};
