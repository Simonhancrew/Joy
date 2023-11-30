#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }
    int n = word1.size();
    int s1{}, s2{};
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < n; i++) {
      auto a = word1[i], b = word2[i];
      s1 |= 1 << (a - 'a');
      s2 |= 1 << (b - 'a');
      cnt1[a - 'a']++;
      cnt2[b - 'a']++;
    }
    if (s1 != s2) {
      return false;
    }
    sort(cnt1.begin(), cnt1.end());
    sort(cnt2.begin(), cnt2.end());
    return cnt1 == cnt2;
  }
};
