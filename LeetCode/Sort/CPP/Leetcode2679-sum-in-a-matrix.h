#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int matrixSum(vector<vector<int>>& nums) {
    int ans{};
    int n = nums.size(), m = nums[0].size();
    for (auto& x : nums) {
      sort(x.begin(), x.end());
    }
    for (int i = m - 1; i >= 0; i--) {
      int cur = -1;
      for (int j = 0; j < n; j++) {
        cur = max(cur, nums[j][i]);
      }
      // cout << i << ' ' << cur << endl;
      ans += cur;
    }
    return ans;
  }
};
