class Solution {
 public:
  int longestSubarray(vector<int> &nums) {
    int l = 0, cnt = 0, l0 = -1, n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cnt += 1 - nums[i];
      if (cnt > 1) {
        cnt--;
        l  = l0 + 1;
        l0 = i;
        continue;
      }
      if (nums[i] == 0) {
        l0 = i;
      }
      ans = max(ans, i - l);
    }
    return ans;
  }
};
