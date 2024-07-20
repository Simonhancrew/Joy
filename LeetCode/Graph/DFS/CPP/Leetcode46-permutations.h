#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int> cur(n);
    vector<int> st(n);
    auto dfs = [&](auto &&dfs, int i) {
      if (i == n) {
        ans.emplace_back(cur);
        return;
      }
      for (int j = 0; j < n; j++) {
        if (!st[j]) {
          cur[i] = nums[j];
          st[j] = true;
          dfs(dfs, i + 1);
          st[j] = false;
        }
      }
    };
    dfs(dfs, 0);
    return ans;
  }
};
