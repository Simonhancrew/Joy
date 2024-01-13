#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> rec(26);
    for (const auto x : s) {
      rec[x - 'a']++;
    }
    string res;
    int pre = -1;
    bool is_limit = false;
    while (true) {
      bool flag = true;
      for (int i = 25; i >= 0; i--) {
        if (rec[i] > 0 && pre != i) {
          int limit = repeatLimit;
          if (is_limit)
            limit = 1;
          int add = min(limit, rec[i]);
          res += string(add, 'a' + i);
          rec[i] -= add;
          pre = i;
          flag = false;
          if (!is_limit && rec[i] > 0)
            is_limit = true;
          else if (is_limit)
            is_limit = false;
          break;
        }
      }
      if (flag)
        break;
    }
    return res;
  }
};
