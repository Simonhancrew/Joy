/*
  NOTE: 贪心，找到最大的两个数和最小的两个数，然后比较两个数的差值
  左边的mx + mn跟右边的数组B对比，B是遍历的右端点，左边选取之前的最小值 + 最大值
*/
class Solution {
 public:
  int maxDistance(vector<vector<int>> &arrays) {
    int mn = INT_MAX / 2, mx = INT_MIN / 2;
    int ans = 0;
    for (const auto x : arrays) {
      ans = max({ans, x.back() - mn, mx - x.front()});
      mn  = min(mn, x.front());
      mx  = max(mx, x.back());
    }
    return ans;
  }
};
