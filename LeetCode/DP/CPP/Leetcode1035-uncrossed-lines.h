#include <vector>

using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> f(n, vector<int>(m, -1));
    auto dfs = [&](auto &&dfs, int i, int j) {
      if (i < 0 || j < 0) {
        return 0;
      }
      auto &res = f[i][j];
      if (res != -1) {
        return res;
      }
      res = 0;
      if (nums1[i] == nums2[j]) {
        return res = dfs(dfs, i - 1, j - 1) + 1;
      }
      return res = max(dfs(dfs, i - 1, j), dfs(dfs, i, j - 1));
    };
    return dfs(dfs, n - 1, m - 1);
  }
};
