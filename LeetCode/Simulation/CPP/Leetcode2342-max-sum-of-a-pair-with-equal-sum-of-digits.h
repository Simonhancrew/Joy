#include <unordered_map>

using namespace std;

class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    int ans = -1;
    auto calcu = [](int x) {
      int sum = 0;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    };
    for (int i = 0; i < n; i++) {
      auto x = calcu(nums[i]);
      if (mp.count(x)) {
        ans = max(ans, mp[x] + nums[i]);
        mp[x] = max(mp[x], nums[i]);
      } else {
        mp[x] = nums[i];
      }
    }
    return ans;
  }
};
