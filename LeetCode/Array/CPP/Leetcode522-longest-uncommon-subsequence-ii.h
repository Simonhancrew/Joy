#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static int Lcs(const std::string &a, const std::string &b) {
    vector<vector<int>> f(a.size(), vector<int>(b.size(), -1));
    auto dfs = [&a, &b, &f](auto &&self, int i, int j) {
      if (i == a.size() || j == b.size()) {
        return 0;
      }
      auto &res = f[i][j];
      if (res != -1) {
        return res;
      }
      if (a[i] == b[j]) {
        return res = 1 + self(self, i + 1, j + 1);
      }
      return res = max(self(self, i + 1, j), self(self, i, j + 1));
    };
    return dfs(dfs, 0, 0);
  }

  int findLUSlength(vector<string> &strs) {
    int n = strs.size();
    ranges::sort(strs, [](auto &l, auto &r) { return l.size() > r.size(); });
    for (int i = 0; i < n; i++) {
      int sz = strs[i].size();
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (Lcs(strs[i], strs[j]) == strs[i].size()) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return strs[i].size();
      }
    }
    return -1;
  }
};
