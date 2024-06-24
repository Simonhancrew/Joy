#include <vector>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> stk;
    vector<int> res;
    int n = nums.size();
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!stk.empty() && stk.back() <= nums[i % n])
        stk.pop_back();
      int cur = stk.empty() ? -1 : stk.back();
      stk.push_back(nums[i % n]);
      res.push_back(cur);
    }
    reverse(res.begin(), res.end());
    return {res.begin(), res.begin() + n};
  }
};
