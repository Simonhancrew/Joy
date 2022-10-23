class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    int n = min(word1.size(), word2.size());
    string ans;
    for (int i = 0; i < n; i++) {
      ans += word1[i];
      ans += word2[i];
    }
    if (n != word1.size()) ans += word1.substr(n);
    if (n != word2.size()) ans += word2.substr(n);
    return ans;
  }
};