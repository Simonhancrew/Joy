#include <string>

using namespace std;

class Solution {
 public:
  bool areNumbersAscending(string s) {
    int n = s.size();
    int pre = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') continue;
      int j = i;
      while (j < n && s[j] != ' ') j++;
      if (s[i] < '0' || s[i] > '9') {
        i = j - 1;
        continue;
      }
      auto str = s.substr(i, j - i);
      int cur = stoi(str);
      if (cur <= pre) return false;
      pre = cur;
      i = j - 1;
    }
    return true;
  }
};
