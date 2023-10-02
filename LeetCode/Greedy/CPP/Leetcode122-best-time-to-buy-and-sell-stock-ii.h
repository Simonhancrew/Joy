#include <vector>

using namespace std;

// 看成单天交易，分解到每一天，区间买卖其实就是单天交易是正的累加

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i + 1 < n; i++) {
      ans += max(0, prices[i + 1] - prices[i]);
    }
    return ans;
  }
};
