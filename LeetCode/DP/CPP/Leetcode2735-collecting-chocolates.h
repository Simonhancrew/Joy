#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long minCost(vector<int>& nums, int x) {
    int n = nums.size();
    vector<int> rec = nums;
    LL ans = accumulate(nums.begin(), nums.end(), 0ll);
    for (int k = 1; k < n; k++) {
      for (int i = 0; i < n; i++) {
        rec[i] = min(rec[i], nums[(i + k) % n]);
      }
      ans = min(ans, (LL)k * x + accumulate(rec.begin(), rec.end(), 0ll));
    }
    return ans;
  }
};
