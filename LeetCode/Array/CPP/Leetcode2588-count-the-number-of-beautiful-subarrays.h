class Solution {
 public:
  long long beautifulSubarrays(vector<int> &nums) {
    using LL = long long;
    LL ans   = 0;
    int acc  = 0;
    unordered_map<int, int> mp{{0, 1}};
    for (const auto x : nums) {
      acc ^= x;
      ans += mp[acc]++;
    }
    return ans;
  }
};
