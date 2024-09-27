// 只用算长度为minSize的子串，因为长度为minSize的子串的子串一定是长度为minSize的子串
class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> mp;
    int n = s.size();
    string temp;
    int cnt[26]{}, acc{};
    int ans = 0;
    for (int i = 0; i < n; i++) {
      temp.push_back(s[i]);
      cnt[s[i] - 'a']++;
      if (cnt[s[i] - 'a'] == 1)
        acc++;
      if (i < minSize - 1)
        continue;
      if (acc <= maxLetters) {
        mp[temp]++;
      }
      ans = max(ans, mp[temp]);
      auto c = temp[0];
      temp.erase(temp.begin());
      cnt[c - 'a']--;
      if (cnt[c - 'a'] == 0)
        acc--;
    }
    return ans;
  }
};
