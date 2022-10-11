#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2)
      return true;
    int n = s1.size(), cnt = 0;
    vector<int> r1(26), r2(26);
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i])
        cnt++;
      r1[s1[i] - 'a']++;
      r2[s2[i] - 'a']++;
    }
    if (cnt > 2)
      return false;
    for (int i = 0; i < 26; i++) {
      if (r1[i] != r2[i])
        return false;
    }
    return true;
  }
};