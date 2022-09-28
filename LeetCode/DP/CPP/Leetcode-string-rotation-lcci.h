#include <vector>

using namespace std;

class Solution {
 public:
  bool isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    if (s1 == s2)
      return true;
    string s = s1 + s1;
    int n = s2.size(), m = s.size();
    vector<int> ne(n);
    ne[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
      while (j != -1 && s2[j + 1] != s2[i])
        j = ne[j];
      if (s2[j + 1] == s2[i])
        j++;
      ne[i] = j;
    }
    for (int i = 0, j = -1; i < m; i++) {
      while (j != -1 && s2[j + 1] != s[i])
        j = ne[j];
      if (s[i] == s2[j + 1])
        j++;
      if (j == n - 1) {
        // cout << i << ' ' << j << '\n';
        // j = ne[j];
        return true;
      }
    }
    return false;
  }
};