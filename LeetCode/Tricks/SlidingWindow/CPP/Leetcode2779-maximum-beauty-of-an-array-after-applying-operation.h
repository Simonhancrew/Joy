#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumBeauty(vector<int> &nums, int k) {
    ranges::sort(nums);
    int n = nums.size();
    int ans{};
    int i = 0;
    for (int j = 0; j < n; j++) {
      while (i <= j && nums[j] - nums[i] > 2 * k) {
        i++;
      }
      ans = max(ans, j - i + 1);
    }
    return ans;
  }
};
