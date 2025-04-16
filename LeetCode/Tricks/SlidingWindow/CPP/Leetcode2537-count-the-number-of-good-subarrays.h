class Solution {
 public:
  using LL = long long;
  long long countGood(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int l = 0, n = nums.size();
    int pairs = 0;
    LL ans    = 0;
    for (int r = 0; r < n; ++r) {
      auto cnt = mp[nums[r]];
      pairs += cnt;
      mp[nums[r]]++;
      while (l < r && pairs >= k) {
        mp[nums[l]]--;
        pairs -= mp[nums[l]];
        l++;
      }
      ans += l;
    }
    return ans;
  }
};
