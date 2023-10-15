#include <vector>

using namespace std;

class Solution {
 public:
  using LL = long long;
  vector<int> singleNumber(vector<int>& nums) {
    LL pa = 0;
    for (const auto x : nums) {
      pa ^= x;
    }
    LL low = pa & (-pa);
    LL a = 0, b = 0;
    for (const auto x : nums) {
      if (low & x)
        a ^= x;
      else
        b ^= x;
    }
    vector<int> ans(2);
    ans[0] = a, ans[1] = b;
    return ans;
  }
};
