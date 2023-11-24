#include <vector>
#include <algorithm>

using namespace std;

// 翻译一下，不重不漏的找数对，交换位置不重复算在内，和小于target，sort之后用双指针

class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int ans = 0;
    while (i < j) {
      if (nums[i] + nums[j] < target) {
        ans += j - i;
        i += 1;
      } else {
        j -= 1;
      }
    }
    return ans;
  }
};
