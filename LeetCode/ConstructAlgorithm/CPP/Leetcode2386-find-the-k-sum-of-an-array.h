#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>


using namespace std;

// 求非负数和acc，一个子序列和=acc - 正数或acc + 负数
// 都等价于acc - abs(x), 现在要求第k大，可以转化为求sum<abs(x)>的第k小
// 这里要注意的是空集也算，最小

class Solution {
public:
  using LL = long long;
  long long kSum(vector<int> &nums, int k) {
    LL acc = 0;
    for (auto &x : nums) {
      if (x > 0)
        acc += x;
      else
        x = -x;
    }
    sort(nums.begin(), nums.end());

    auto check = [&](LL sum_limit) {
      int cnt = 1;
      function<void(int, LL)> dfs = [&](int i, LL s) {
        if (cnt == k || i == nums.size() || s + nums[i] > sum_limit) {
          return;
        }
        ++cnt;
        dfs(i + 1, s + nums[i]);
        dfs(i + 1, s);
      };
      dfs(0, 0);
      return cnt == k;
    };

    LL l = -1, r = accumulate(nums.begin(), nums.end(), 0ll);
    while (l + 1 < r) {
      auto mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    return acc - r;
  }
};
