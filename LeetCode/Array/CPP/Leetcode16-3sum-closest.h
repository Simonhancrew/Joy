#include <algorithm>
#include <vector>

using namespace std;

// 排序之后转换成3数之和，有恰好target的，当前点就是答案
// 否则，没有target值，要么这个值是target左侧最大，或者是右侧最小
// 做一次判断就可以了

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    pair<int, int> res{INT_MAX, INT_MAX};
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
      if (i && nums[i - 1] == nums[i]) continue;
      for (int j = i + 1, k = n - 1; j < k; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        while (j < k - 1 && nums[i] + nums[j] + nums[k] > target) k--;
        auto sum = nums[i] + nums[j] + nums[k];
        res = min(res, make_pair(abs(target - sum), sum));
        if (j < k - 1) {
          sum = nums[i] + nums[j] + nums[k - 1];
          res = min(res, make_pair(abs(target - sum), sum));
        }
      }
    }
    return res.second;
  }
};
