class Solution {
 public:
  int longestSubarray(vector<int> &nums) {
    int ans = 1, n = nums.size(), tar = 0;
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      while (j < n && nums[j] == nums[i])
        ++j;
      if (tar < nums[i]) {
        tar = nums[i];
        ans = j - i;
      } else if (tar == nums[i]) {
        ans = max(ans, j - i);
      }
      i = j - 1;
    }
    return ans;
  }
};
