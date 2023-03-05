class Solution {
 public:
  int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
    int tot = 0, profit = 0, res = 0, mx_profit = 0;
    for (int i = 0, n = customers.size(); i < n || tot > 0; i++) {
      if (i < n) {
        tot += customers[i];
      }
      if (tot >= 4) {
        profit += boardingCost * 4 - runningCost;
        tot -= 4;
      } else {
        profit += boardingCost * tot - runningCost;
        tot = 0;
      }

      if (mx_profit < profit) {
        mx_profit = profit;
        res = i;
      }
    }
    if (mx_profit <= 0) {
      return -1;
    }
    return res + 1;
  }
};
