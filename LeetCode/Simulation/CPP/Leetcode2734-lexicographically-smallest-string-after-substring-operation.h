#include <string>

using namespace std;

class Solution {
public:
  string smallestString(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        continue;
      }
      while (i < n && s[i] != 'a') {
        s[i]--;
        i++;
      }
      return s;
    }
    s.back() = 'z';
    return s;
  }
};
