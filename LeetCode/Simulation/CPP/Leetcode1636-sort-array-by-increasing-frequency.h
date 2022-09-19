class Solution {
 public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      mp[nums[i]]++;
    }
    sort(nums.begin(), nums.end(), [&mp](int lhs, int rhs) {
      if (mp[lhs] == mp[rhs])
        return lhs > rhs;
      return mp[lhs] < mp[rhs];
    });
    return nums;
  }
};