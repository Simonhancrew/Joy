#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> nums;
  int target{};
  vector<unordered_map<int, int>> f;
  int dfs(int i, int acc) {
    if (i == nums.size()) {
      if (acc == 0) {
        return 1;
      }
      return 0;
    }
    if (f[i].count(acc)) {
      return f[i][acc];
    }
    f[i][acc] = 0;
    auto &res = f[i][acc];
    res += dfs(i + 1, acc + nums[i]);
    res += dfs(i + 1, acc - nums[i]);
    return res;
  }
  int findTargetSumWays(vector<int> &nums, int target) {
    this->target = target;
    this->nums = std::move(nums);
    f.resize(this->nums.size());
    return dfs(0, target);
  }
};
