// 区间size的，[l, r]. 可以用r的upper_bound - l的lower_bound来计算
class Solution {
 public:
  using LL = long long;
  // j > i
  // nums[j] >= lower - num[i], nums[j] <= upper - nums[i];
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    ranges::sort(nums);
    int n  = nums.size();
    LL res = 0;
    for (int i = 0; i < n - 1; i++) {
      auto l = i, r = n;
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (nums[mid] < lower - nums[i])
          l = mid;
        else
          r = mid;
      }
      int pre = r;
      l = i, r = n;
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (nums[mid] <= upper - nums[i])
          l = mid;
        else
          r = mid;
      }
      res += r - pre;
    }
    return res;
  }
};
