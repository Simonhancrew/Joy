class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    int ans = 0;
    sort(coins.begin(), coins.end());
    for (const auto& c : coins) {
      if (c > ans + 1) return ans + 1;
      ans += c;
    }
    return ans + 1;
  }
};