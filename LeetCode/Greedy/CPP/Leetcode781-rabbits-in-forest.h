class Solution {
 public:
  int numRabbits(vector<int> &answers) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (const auto x : answers) {
      mp[x]++;
    }
    for (const auto [k, v] : mp) {
      if (k == 0) {
        ans += v;
        continue;
      }
      ans += (v + k) / (k + 1) * (k + 1);
    }
    return ans;
  }
};
