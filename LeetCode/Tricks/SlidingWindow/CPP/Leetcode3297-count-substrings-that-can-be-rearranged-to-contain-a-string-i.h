class Solution {
 public:
  using LL = long long;
  long long validSubstringCount(string word1, string word2) {
    if (word1.size() > word1.size()) {
      return 0;
    }
    int cnt[26]{};
    for (int i = 0; i < word2.size(); ++i) {
      cnt[word2[i] - 'a']++;
    }
    int sz = 0;
    for (const auto c : cnt) {
      if (c > 0) {
        sz++;
      }
    }
    LL ans = 0;
    int l  = 0;
    for (int r = 0; r < word1.size(); ++r) {
      auto c = word1[r] - 'a';
      cnt[c]--;
      if (cnt[c] == 0) {
        sz--;
      }
      while (sz == 0) {
        auto out = word1[l++] - 'a';
        if (cnt[out] == 0) {
          sz++;
        }
        cnt[out]++;
      }
      ans += l;
    }
    return ans;
  }
};
