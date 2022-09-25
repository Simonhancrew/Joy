#include <vector>
#include <string>

using namespace std;

// 数位dp牢记，不贴上界，且无前导零

class Solution {
 public:
  int len;
  string s;
  vector<vector<int>> f;
  int diffs[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
  int dfs(int pos, bool diff, bool limit) {
    if (pos == len)
      return diff;
    if (!limit && f[pos][diff] != -1)
      return f[pos][diff];
    int up  = limit ? s[pos] - '0' : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
      if (diffs[i] != -1) {
        res += dfs(pos + 1, diff || diffs[i], limit && i == up);
      }
    }
    if (!limit)
      f[pos][diff] = res;
    return res;
  }

  int rotatedDigits(int n) {
    s   = to_string(n);
    len = s.length();
    f   = vector<vector<int>>(len, vector<int>(2, -1));
    return dfs(0, false, true);
  }
};