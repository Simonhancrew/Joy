class Solution {
 public:
  using LL = long long;
  long long countBadPairs(vector<int> &nums) {
    unordered_map<int, int> mp;
    LL ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int tar = i - nums[i];
      ans += (i - mp[tar]);
      mp[tar]++;
    }
    return ans;
  }
};
