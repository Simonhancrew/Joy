#include <cstring>
#include <vector>

using namespace std;

class Solution {
 public:
  static const int N = 1e3 + 10;
  static const int K = 110;
  // 前i天，进行过k次交易(可能还在进行)，手中是否持有股票
  int f[N][K][2];
  int maxProfit(int k, vector<int>& prices) {
    auto n = prices.size();
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[i][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        // 持有股票，交易完成，加上利润
        f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
        // 未持有，开始交易，减去第一天的成本
        f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
      }
    }
    int res = 0;
    for (int i = 0; i <= k; i++) {
      res = max(res, f[n][i][0]);
    }
    return res;
  }
};
