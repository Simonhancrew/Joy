#include <vector>

using namespace std;

class Solution {
public:
  vector<int> arr;
  vector<vector<int>> f;
  int dfs(int pos, int pre, bool limit, bool lead) {
    if (pos < 0) {
      return 1;
    }
    if (!limit && !lead && f[pos][pre] != -1) {
      return f[pos][pre];
    }
    int up = limit ? arr[pos] : 1;
    int res = 0;
    for (int i = 0; i <= up; i++) {
      if (pre == 1 && i == 1) {
        continue;
      }
      res += dfs(pos - 1, i, limit && i == up, lead && i == 0);
    }
    if (!limit && !lead) {
      f[pos][pre] = res;
    }
    return res;
  }

  int findIntegers(int n) {
    while (n) {
      arr.push_back(n % 2);
      n /= 2;
    }
    f.resize(arr.size(), vector<int>(2, -1));
    return dfs(arr.size() - 1, 0, 1, 1);
  }
};
