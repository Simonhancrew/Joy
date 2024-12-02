#include <vector>

using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    vector<int> col(n), dg(2 * n), rdg(2 * n);
    int ans  = 0;
    auto dfs = [&](auto &&dfs, int row) {
      if (row == n) {
        ans++;
        return;
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (col[i] || dg[i + row] || rdg[n - row + i])
          continue;
        col[i] = dg[i + row] = rdg[n - row + i] = 1;
        dfs(dfs, row + 1);
        col[i] = dg[i + row] = rdg[n - row + i] = 0;
      }
    };
    dfs(dfs, 0);
    return ans;
  }
};
