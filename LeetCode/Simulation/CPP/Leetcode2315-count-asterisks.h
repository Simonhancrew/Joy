class Solution {
 public:
  int countAsterisks(string s) {
    int ans = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '|') {
        i++;
        while (i < n && s[i] != '|') i++;
      } else if (s[i] == '*') {
        ans++;
      }
    }
    return ans;
  }
};