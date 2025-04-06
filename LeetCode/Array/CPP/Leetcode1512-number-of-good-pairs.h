class Solution {
 public:
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (const auto x : nums) {
      if (mp.count(x)) {
        ans += mp[x];
      }
      mp[x]++;
    }
    return ans;
  }
};
