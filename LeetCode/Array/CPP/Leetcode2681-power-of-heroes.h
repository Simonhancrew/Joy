#include <algorithm>
#include <vector>

using namespace std;

// 因为只要最大值最小值，且只要子序列
// 可以让数组变有序之后枚举最大值和最小值
// 枚举 + 数学
// 然后找前后两者之间的数学关系做变换就可以了

class Solution {
 public:
  static const int MOD = 1e9 + 7;
  using LL = long long;
  int sumOfPower(vector<int>& nums) {
    int ans = 0, s = 0;
    sort(nums.begin(), nums.end());
    for (const auto x : nums) {
      ans = (ans + ((LL)x * x % MOD) * (x + s)) % MOD;
      s = ((LL)s * 2 + x) % MOD;
    }
    return ans;
  }
};