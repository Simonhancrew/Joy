#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> pre_sum(n, 0);
    for (int i = 1; i < n; i++) {
      pre_sum[i] = pre_sum[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);
    }
    vector<bool> ans;
    n = queries.size();
    ans.reserve(n);
    for (const auto &q : queries) {
      ans.push_back(pre_sum[q[0]] == pre_sum[q[1]]);
    }
    return ans;
  }
};
