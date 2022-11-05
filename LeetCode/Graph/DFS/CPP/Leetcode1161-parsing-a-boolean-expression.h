#include <functional>

using namespace std;

class Solution {
 public:
  bool parseBoolExpr(string s) {
    int n = s.size(), i = 0;
    function<bool()> dfs = [&]() {
      if (s[i] == 't') {
        i++;
        return true;
      }
      if (s[i] == 'f') {
        i++;
        return false;
      }
      // op
      char op = s[i];
      i += 2;
      bool res = true;
      if (op == '|') res = false;
      while (s[i] != ')') {
        if (s[i] == ',')
          i++;
        else {
          auto t = dfs();
          if (op == '|')
            res |= t;
          else
            res &= t;
        }
      }
      i++;
      if (op == '!') res = !res;
      return res;
    };
    return dfs();
  }
};