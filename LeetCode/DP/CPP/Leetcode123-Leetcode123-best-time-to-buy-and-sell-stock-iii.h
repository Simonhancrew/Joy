#include <vector>

using namespace std;

// dp，正向算一次交易的最大值
// 逆向算第二次交易的最大值，然后+f[i - 1]

class Solution {
 public:
  static int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> f(n + 1);
    int pre_min = INT_MAX;
    for (int i = 1; i <= n; i++) {
      f[i] = max(f[i - 1], prices[i - 1] - pre_min);
      pre_min = min(pre_min, prices[i - 1]);
    }
    int aft_mx = 0;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      ans = max(ans, f[i - 1] + aft_mx - prices[i - 1]);
      aft_mx = max(aft_mx, prices[i - 1]);
    }
    return ans;
  }
};
