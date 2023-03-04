class Solution {
 public:
  int countTriplets(vector<int>& nums) {
    int res = 0, n = nums.size();
    vector<int> mp(1 << 16);
    for (const auto& num : nums) {
      for (const auto& x : nums) {
        auto y = num & x;
        mp[y]++;
      }
    }
    for (const auto& x : nums) {
      for (int i = 0; i < 1 << 16; i++) {
        if ((x & i) == 0) {
          res += mp[i];
        }
      }
    }
    return res;
  }
};