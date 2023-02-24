class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0, cur = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (cur == nums[i]) continue;
      if (cur < nums[i]) {
        cur = nums[i];
        res++;
      }
    }
    return res;
  }
};
