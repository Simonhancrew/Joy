#include <vector>

using namespace std;

// 思考最后一位，选择的是偶数位还是奇数位
// 然后做转移

class Solution {
 public:
  using LL = long long;
  static constexpr int INF = 0x3f3f3f3f;
  long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<LL>> f(n, vector<LL>(2, -INF));
    f[0][0] = nums[0], f[0][1] = 0;
    for (int i = 1; i < n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i]);
      f[i][1] = max(f[i - 1][1], f[i - 1][0] - nums[i]);
    }
    return max(f[n - 1][0], f[n - 1][1]);
  }
};
