#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    int mx = nums[0][1];
    for_each(nums.begin(), nums.end(),
             [&mx](auto& num) { mx = max(num[1], mx); });
    vector<int> dis(mx + 2);
    for (const auto& x : nums) {
      dis[x[0]]++;
      dis[x[1] + 1]--;
    }
    int acc = 0;
    int ans = 0;
    for (int i = 0; i < dis.size(); i++) {
      acc += dis[i];
      ans += (acc > 0);
    }
    return ans;
  }
};
