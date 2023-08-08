#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> l, r;
  int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    l.resize(n, INT_MIN);
    l[0] = nums[0];
    int ans = abs(l[0]);
    for (int i = 1; i < n; i++) {
      l[i] = max(l[i - 1] + nums[i], nums[i]);
      ans = max(ans, abs(l[i]));
    }
    r.resize(n, INT_MAX);
    r[0] = nums[0];
    for (int i = 1; i < n; i++) {
      r[i] = min(r[i - 1] + nums[i], nums[i]);
      ans = max(ans, abs(r[i]));
    }
    return ans;
  }
};
