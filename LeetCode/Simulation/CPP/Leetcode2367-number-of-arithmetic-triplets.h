class Solution {
 public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (nums[j] - nums[i] != diff) continue;
        for (int k = j; k < n; k++) {
          if (nums[k] - nums[j] != diff) continue;
          ans++;
        }
      }
    }
    return ans;
  }
};