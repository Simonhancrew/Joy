#include <vector>

using namespace std;

class Solution {
public:
  bool validPartition(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
      if (f[i - 1] && nums[i] == nums[i - 1] ||
          i > 1 && f[i - 2] &&
              (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||
               nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)) {
        f[i + 1] = true;
      }
    }
    return f[n];
  }
};
