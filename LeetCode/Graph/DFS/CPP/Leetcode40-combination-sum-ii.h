class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    auto dfs = [&](auto &&dfs, int idx, int left) {
      if (left == 0) {
        ans.push_back(tmp);
        return;
      }
      for (int i = idx; i < candidates.size() && left >= candidates[i]; ++i) {
        if (i > idx && candidates[i] == candidates[i - 1]) {
          continue;
        }
        tmp.push_back(candidates[i]);
        dfs(dfs, i + 1, left - candidates[i]);
        tmp.pop_back();
      }
    };
    dfs(dfs, 0, target);
    return ans;
  }
};
