#include <vector>

using namespace std;

// 状态机dp，这种问题能想到买的时候把当前价格做负收益就比较好想

class Solution {
 public:
  static const int INF = 0x3f3f3f3f;
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> f(2, vector<int>(3));
    f[0][0] = -INF, f[0][1] = -INF, f[0][2] = 0;
    for (int i = 1; i <= n; i++) {
      f[i & 1][0] = max(f[i - 1 & 1][0], f[i - 1 & 1][2] - prices[i - 1]);
      f[i & 1][1] = f[i - 1 & 1][0] + prices[i - 1];
      f[i & 1][2] = max(f[i - 1 & 1][1], f[i - 1 & 1][2]);
    }
    return max(f[n & 1][1], f[n & 1][2]);
  }
};
