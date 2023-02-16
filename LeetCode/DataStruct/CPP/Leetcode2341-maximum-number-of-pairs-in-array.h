class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans = {0, n};
    unordered_map<int, int> mp;
    for (auto num : nums) mp[num]++;
    for (auto num : nums) {
      if (mp[num] >= 2) {
        ans[0]++;
        ans[1] -= 2;
        mp[num] -= 2;
      }
    }
    return ans;
  }
};
