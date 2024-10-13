class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int l = 0, n = s.size(), ans{}, cnt[128]{};
    for (int r = 0; r < n; r++) {
      cnt[s[r]]++;
      while (cnt[s[r]] > 1) {
        cnt[s[l++]]--;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
