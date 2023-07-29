#include <vector>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long maxArrayValue(vector<int>& nums) {
    LL ans = 0;
    auto n = nums.size();
    auto i = n - 1;
    while (i >= 0) {
      LL s = nums[i];
      while (i > 0 && nums[i - 1] <= s) {
        s += nums[i - 1];
        i--;
      }
      ans = max(ans, s);
      i--;
    }
    return ans;
  }
};
