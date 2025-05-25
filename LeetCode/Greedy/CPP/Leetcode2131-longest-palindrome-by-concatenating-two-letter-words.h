class Solution {
 public:
  int longestPalindrome(vector<string> &words) {
    int cnt[26][26]{};
    for (const auto &s : words) {
      cnt[s[0] - 'a'][s[1] - 'a']++;
    }
    int ans = 0, odd = 0;
    for (int i = 0; i < 26; i++) {
      int c = cnt[i][i];
      ans += c - c % 2;
      odd |= c % 2;
      for (int j = i + 1; j < 26; j++) {
        ans += min(cnt[i][j], cnt[j][i]) * 2;
      }
    }
    return (ans + odd) * 2;
  }
};
