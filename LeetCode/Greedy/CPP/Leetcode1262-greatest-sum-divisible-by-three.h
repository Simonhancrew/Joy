class Solution {
 public:
  int maxSumDivThree(vector<int>& nums) {
    int s1 = 1e5, s2 = 1e5;
    int t1 = 1e5, t2 = 1e5;
    int sum = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (nums[i] % 3 == 1) {
        if (s1 >= nums[i])
          s2 = s1, s1 = nums[i];
        else if (s2 >= nums[i])
          s2 = nums[i];
      } else if (nums[i] % 3 == 2) {
        if (t1 >= nums[i])
          t2 = t1, t1 = nums[i];
        else if (t2 >= nums[i])
          t2 = nums[i];
      }
    }
    if (sum % 3 == 0) return sum;
    if (sum % 3 == 1) {
      return max(sum - s1, sum - t1 - t2);
    }
    return max(sum - s1 - s2, sum - t1);
  }
};
