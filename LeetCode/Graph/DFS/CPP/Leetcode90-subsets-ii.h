class Solution {
 public:
  vector<vector<int>> res;
  vector<int> cur;
  void dfs(vector<int> &nums, int idx) {
    if (idx == nums.size()) {
      res.push_back(cur);
      return;
    }
    cur.push_back(nums[idx]);
    dfs(nums, idx + 1);
    cur.pop_back();
    auto now = idx++;
    while (idx < nums.size() && nums[idx] == nums[now]) {
      idx++;
    }
    dfs(nums, idx);
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    dfs(nums, 0);
    return move(res);
  }
};
