class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> rec(26, -1);
    int n = s.size(), ans = -1;
    for (int i = 0; i < n; i++) {
      if (rec[s[i] - 'a'] < 0) {
        rec[s[i] - 'a'] = i;
      } else {
        ans = max(ans, i - rec[s[i] - 'a'] - 1);
      }
    }
    return ans;
  }
};
