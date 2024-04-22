#include <array>
#include <functional>
#include <vector>


using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    array<int, 1010> f;
    memset(f.data(), -1, sizeof(f));
    function<int(int)> dfs = [&](int sum) {
      if (f[sum] != -1) {
        return f[sum];
      }
      auto &res = f[sum];
      res = 0;
      if (sum == target) {
        res = 1;
        return 1;
      }
      for (const auto x : nums) {
        if (sum + x <= target) {
          res += dfs(sum + x);
        }
      }
      return res;
    };
    return dfs(0);
  }
};
