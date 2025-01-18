class Solution {
 public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int ans = INT_MAX;
    int n   = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] >= k) {
        return 1;
      }
      int j = i - 1;
      // NOTE: | and =, |'s priority is lower than =, so we need to use ()
      while (j >= 0 && (nums[j] | nums[i]) != nums[j]) {
        nums[j] |= nums[i];
        if (nums[j] >= k) {
          ans = min(ans, i - j + 1);
        }
        j--;
      }
    }
    return ans < INT_MAX ? ans : -1;
  }
};