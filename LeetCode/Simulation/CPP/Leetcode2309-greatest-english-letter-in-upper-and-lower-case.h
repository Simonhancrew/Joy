class Solution {
 public:
  string greatestLetter(string s) {
    vector<int> lo(26), up(26);
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        lo[s[i] - 'a']++;
        if (up[s[i] - 'a'] > 0 && (ans.empty() || ans[0] - 'A' < s[i] - 'a')) {
          ans = toupper(s[i]);
        }
      } else {
        up[s[i] - 'A']++;
        if (lo[s[i] - 'A'] > 0 && (ans.empty() || ans[0] < s[i])) {
          ans = s[i];
        }
      }
    }
    return ans;
  }
};