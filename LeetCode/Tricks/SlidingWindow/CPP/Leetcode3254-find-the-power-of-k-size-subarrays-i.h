#include <vector>

using namespace std;

class Solution {
public:
  vector<int> resultsArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ans(n - k + 1, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 || nums[i - 1] == nums[i] - 1)
        cnt += 1;
      else
        cnt = 1;
      if (cnt >= k) {
        ans[i - k + 1] = nums[i];
      }
    }
    return ans;
  }
};
