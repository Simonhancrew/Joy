#include <algorithm>
#include <vector>

using namespace std;

// 反向思路，最多能留下多少数，因为顺序无关，所以可以排序后找一个窗口

class Solution {
public:
  static int minOperations(vector<int> &nums) {
    ranges::sort(nums);
    int n = nums.size();
    auto lst = ranges::unique(nums);
    nums.erase(lst.begin(), nums.end());
    int left = 0;
    int ans = 0;
    for (int i = 0, tot = nums.size(); i < tot; i++) {
      while (nums[left] < nums[i] - n + 1) {
        left += 1;
      }
      ans = max(ans, i - left + 1);
    }
    return n - ans;
  }
};
