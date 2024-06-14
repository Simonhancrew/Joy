#include <vector>

using namespace std;

// -std>=c++14

class Solution {
 public:
  using LL = long long;
  long long maxScore(vector<int> &nums, int x) {
    int n = nums.size();
    vector<vector<LL>> f(n, vector<LL>(2, -1));
    auto dfs = [&](auto &&dfs, int id, int odd) {
      if (id >= n) {
        return 0ll;
      }
      auto &res = f[id][odd];
      if (res != -1) {
        return res;
      }
      res = 0;
      LL cur = nums[id] + dfs(dfs, id + 1, nums[id] & 1);
      if ((nums[id] & 1) != odd) {
        cur -= x;
      }
      res = max(res, cur);
      cur = dfs(dfs, id + 1, odd);
      res = max(res, cur);
      return res;
    };
    return (LL)nums[0] + dfs(dfs, 1, nums[0] & 1);
  }
};