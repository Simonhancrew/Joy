#include <algorithm>
#include <functional>
#include <vector>

using namespace std; // NOLINT

class Solution {
public:
  static vector<vector<int>> combinationSum(vector<int> &candidates,
                                            int target) {
    sort(candidates.begin(), candidates.end());
    auto n = candidates.size();
    vector<vector<int>> ans;
    vector<int> cur{};
    int acc{};
    function<void(int)> dfs = [&](int i) {
      if (i < 0) {
        return;
      }
      if (acc == target) {
        ans.push_back(cur);
        return;
      }
      if (acc > target) {
        return;
      }
      cur.push_back(candidates[i]);
      acc += candidates[i];
      dfs(i);
      cur.pop_back();
      acc -= candidates[i];
      dfs(i - 1);
    };
    dfs(n - 1);
    return ans;
  }
};
