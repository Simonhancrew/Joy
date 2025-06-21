class Solution {
 public:
  int minimumDeletions(string word, int k) {
    int cnt[26]{};
    for (const auto c : word) {
      cnt[c - 'a']++;
    }
    ranges::sort(cnt);
    int res = 0;
    for (int i = 0; i < 26; ++i) {
      int acc = 0;
      for (int j = i; j < 26; ++j) {
        acc += min(cnt[j], cnt[i] + k);
      }
      res = max(res, acc);
    }
    return word.size() - res;
  }
};
