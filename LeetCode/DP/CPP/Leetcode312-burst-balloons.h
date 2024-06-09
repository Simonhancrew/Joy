#include <vector>
#include <functional>

using namespace std;

// 转换一下思路，换成将气球填满，然后换dfs来做
// 比如填i的时候，左右就是l和r，这个时候不一定有，就做1。
// 方便处理的话，可以在rec数组的两边加上1，这样就不用判断边界了

class Solution {
 public:
  vector<int> rec;
  vector<vector<int>> f;
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    rec.resize(n + 2, 1);
    f.resize(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i <= n; i++) {
      rec[i] = nums[i - 1];
    }
    function<int(int, int)> dfs = [&](int l, int r) {
      if (r - l <= 1) {
        return 0;
      }
      auto &res = f[l][r];
      if (res != -1) return res;
      for (int i = l + 1; i < r; i++) {
        int sum = rec[i] * rec[l] * rec[r];
        sum += dfs(l, i) + dfs(i, r);
        res = max(res, sum);
      }
      return res;
    };
    return dfs(0, n + 1);
  }
};
