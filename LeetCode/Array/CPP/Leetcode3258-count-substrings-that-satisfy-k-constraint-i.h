class Solution {
 public:
  int countKConstraintSubstrings(string s, int k) {
    int ans = 0, l = 0;
    int cnt[2] = {};
    for (int r = 0; r < s.size(); ++r) {
      cnt[s[r] - '0']++;
      while (l < r && !(cnt[0] <= k || cnt[1] <= k))
        cnt[s[l++] - '0']--;
      ans += (r - l + 1);
    }
    return ans;
  }
};