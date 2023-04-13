class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (const auto& num : nums) {
      if (num & 1) continue;
      mp[num] += 1;
    }
    int ans = -1, cnt = 0;
    for (const auto& [k, v] : mp) {
      if (v > cnt) {
        ans = k, cnt = v;
      } else if (v == cnt && ans > k) {
        ans = k;
      }
    }
    return ans;
  }
};
