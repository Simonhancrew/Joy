#include <algorithm>
#include <vector>

// 阶梯放数，从小到大排序，看看能不能放成阶梯状

using namespace std;

class Solution {
 public:
  using LL = long long;
  int maxIncreasingGroups(vector<int>& usageLimits) {
    int ans = 0;
    sort(usageLimits.begin(), usageLimits.end());
    LL acc = 0;
    for (const auto x : usageLimits) {
      acc += x;
      if (acc >= (LL)(ans + 1) * (ans + 2) / 2) {
        ++ans;
      }
    }
    return ans;
  }
};
