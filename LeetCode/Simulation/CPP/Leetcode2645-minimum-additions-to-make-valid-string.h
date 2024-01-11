#include <string>

using namespace std;

class Solution {
public:
  int addMinimum(string s) {
    int cnt = 1;
    int n = s.size();
    for (int i = 1; i < n; i++) {
      if (s[i - 1] >= s[i])
        cnt++;
    }
    return cnt * 3 - n;
  }
};
