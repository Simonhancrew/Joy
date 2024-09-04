#include <algorithm>
#include <vector>

using namespace std;

// 题意解读之后，先排序，以idx为界的话，<=idx的必须选, >idx的数都不选

class Solution {
public:
  int countWays(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i + 1 > nums[i] && !(i + 1 < n && nums[i + 1] <= i + 1)) {
        ans++;
      }
    }
    if (nums[0] != 0)
      ans++;
    return ans;
  }
};
