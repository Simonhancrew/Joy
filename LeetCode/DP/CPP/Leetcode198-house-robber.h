#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n);
    int ans{};
    f[0] = nums[0];
    ans = f[0];
    for (int i = 1; i < n; i++) {
      f[i] = max(f[i - 1], nums[i] + (i - 2 >= 0 ? f[i - 2] : 0));
      ans = max(ans, f[i]);
    }
    return ans;
  }
};