#include <string>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long validSubstringCount(string word1, string word2) {
    if (word2.size() > word1.size()) {
      return 0;
    }
    int cnt[26]{};
    for (const auto c : word2) {
      cnt[c - 'a']++;
    }
    int sz = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0) {
        ++sz;
      }
    }
    int l  = 0;
    LL ans = 0;
    for (int r = 0; r < word1.size(); ++r) {
      auto c = word1[r];
      cnt[c - 'a']--;
      if (cnt[c - 'a'] == 0) {
        sz--;
      }
      while (sz == 0) {
        char out = word1[l++];
        if (cnt[out - 'a']++ == 0) {
          sz++;
          break;
        }
      }
      ans += l;
    }
    return ans;
  }
};
