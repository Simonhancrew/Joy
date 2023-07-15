#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  using LL = long long;
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        for (int k = j + 1, q = n - 1; k < q; k++) {
          if (k > j + 1 && nums[k - 1] == nums[k]) continue;
          while (k < q - 1 &&
                 (LL)nums[i] + nums[j] + nums[k] + nums[q] > target)
            q--;
          if ((LL)nums[i] + nums[j] + nums[k] + nums[q] == target) {
            res.push_back({nums[i], nums[j], nums[k], nums[q]});
          }
        }
      }
    }
    return res;
  }
};
