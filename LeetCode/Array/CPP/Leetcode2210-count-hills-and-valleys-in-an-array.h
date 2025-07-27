class Solution {
 public:
  int countHillValley(vector<int> &nums) {
    int ans = 0, n = nums.size();
    auto m = ranges::unique(nums).begin() - nums.begin();
    // nums.resize(m);
    for (int i = 1; i < m - 1; i++) {
      if ((nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) ||
          (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]))
        ++ans;
    }
    return ans;
  }
};
