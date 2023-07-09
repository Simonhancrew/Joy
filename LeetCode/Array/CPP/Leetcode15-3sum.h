class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1, k = n - 1; j < k; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        while (j + 1 < k) {
          if (nums[i] + nums[j] + nums[k] > 0)
            k--;
          else
            break;
        }
        if (nums[i] + nums[j] + nums[k] == 0) {
          ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
        }
      }
    }
    return ans;
  }
};
