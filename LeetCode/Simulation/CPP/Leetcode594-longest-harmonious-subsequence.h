class Solution {
 public:
  int findLHS(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (const auto x : nums) {
      mp[x]++;
    }
    int ans = 0;
    for (const auto &[k, v] : mp) {
      if (mp.contains(k + 1)) {
        ans = max(ans, v + mp[k + 1]);
      }
    }
    return ans;
  }
};
