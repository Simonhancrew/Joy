#include <string>

using namespace std;

class Solution {
public:
  string getSmallestString(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int d = min(s[i] - 'a', 'z' - s[i] + 1);
      if (d > k) {
        s[i] -= k;
        break;
      }
      s[i] = 'a';
      k -= d;
    }
    return s;
  }
};
