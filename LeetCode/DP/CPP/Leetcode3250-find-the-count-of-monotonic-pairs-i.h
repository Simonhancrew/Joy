#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  int countOfPairs(vector<int> &nums) {
    int res = 0;
    int n   = nums.size();
    vector<vector<int>> f(n, vector<int>(51, -1));
    auto dfs = [&](auto &&dfs, int i, int j) {
      if (i == 0) {
        return 1;
      }
      auto &res = f[i][j];
      if (res != -1) {
        return res;
      }
      res = 0;
      // 0 <= k <= nums[i - 1];
      // k <= j;
      // nums[i - 1] - k >= nums[i] - j
      int mx_k = min({nums[i - 1], j, nums[i - 1] - nums[i] + j});
      for (int k = 0; k <= mx_k; ++k) {
        res = (res + dfs(dfs, i - 1, k)) % MOD;
      }
      return res;
    };
    for (int i = 0; i <= nums.back(); i++) {
      res = (res + dfs(dfs, n - 1, i)) % MOD;
    }
    return res;
  }
};
