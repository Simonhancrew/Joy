class Solution {
 public:
  int similarPairs(vector<string> &words) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (const auto &w : words) {
      int tmp = 0;
      for (const auto c : w) {
        tmp |= 1 << (c - 'a');
      }
      ans += mp[tmp];
      mp[tmp]++;
    }
    return ans;
  }
};
