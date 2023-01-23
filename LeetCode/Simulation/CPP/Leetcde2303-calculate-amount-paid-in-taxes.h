class Solution {
 public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    double ans = 0;
    int pre = 0;
    for (const auto& x : brackets) {
      if (income - x[0] >= 0) {
        ans += (double)(x[0] - pre) * x[1] / 100.0;
        pre = x[0];
      } else {
        ans += (income - pre) * x[1] / 100.0;
        break;
      }
    }
    return ans;
  }
};