#include <vector>

using namespace std;

class Solution {
public:
  static bool canSortArray(vector<int> &nums) {
    int pre_max = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int cur_min = nums[i];
      int cur_max = nums[i];
      auto ones = __builtin_popcount(nums[i]);
      while (j < n && __builtin_popcount(nums[j]) == ones) {
        cur_min = min(cur_min, nums[j]);
        cur_max = max(cur_max, nums[j]);
        j++;
      }
      i = j - 1;
      if (cur_min < pre_max)
        return false;
      pre_max = cur_max;
    }
    return true;
  }
};
