class Solution {
public:
  int takeCharacters(string s, int k) {
    int mp[3] = {};
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
      mp[s[i] - 'a']++;
    }
    for (int i : mp) {
      if (i < k) {
        return -1;
      }
    }
    int j = 0;
    int rec = 0;
    for (int i = 0; i < n; i++) {
      mp[s[i] - 'a']--;
      while (j <= i && mp[s[i] - 'a'] < k) {
        mp[s[j] - 'a']++;
        j++;
      }
      rec = max(rec, i - j + 1);
    }
    return n - rec;
  }
};
