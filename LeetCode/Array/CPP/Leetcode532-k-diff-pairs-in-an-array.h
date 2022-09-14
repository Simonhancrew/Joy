class Solution {
 public:
  int findPairs(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), ans = 0;
    for (int i = 0, j = 0; i < nums.size(); i++) {
      while (i + 1 < n && nums[i + 1] == nums[i]) i++;
      while (j < i && nums[i] - nums[j] > k) j++;
      if (j < i && nums[i] - nums[j] == k) ans++;
    }
    return ans;
  }
};