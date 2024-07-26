#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findValueOfPartition(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      ans = min(ans, abs(nums[i] - nums[i - 1]));
    }
    return ans;
  }
};
