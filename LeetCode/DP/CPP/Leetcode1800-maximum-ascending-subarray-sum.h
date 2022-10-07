class Solution {
 public:
  int maxAscendingSum(vector<int> &nums) {
    int n = nums.size(), ans = nums[0];
    vector<int> f(n);
    f[0] = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        f[i] = f[i - 1] + nums[i];
      } else {
        f[i] = nums[i];
      }
      ans = max(ans, f[i]);
    }
    return ans;
  }
};