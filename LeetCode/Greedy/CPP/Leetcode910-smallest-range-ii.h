/*
  大的变小，小的变大，枚举这个分界线，然后找到最小的差值
  最小值要么在第一段的头部，要么在第二段的头部
  最大值同理
*/
class Solution {
public:
  int smallestRangeII(vector<int> &nums, int k) {
    ranges::sort(nums);
    int ans = nums.back() - nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int mx = max(nums[i - 1] + k, nums.back() - k);
      int mn = min(nums[0] + k, nums[i] - k);
      ans = min(ans, mx - mn);
    }
    return ans;
  }
};
