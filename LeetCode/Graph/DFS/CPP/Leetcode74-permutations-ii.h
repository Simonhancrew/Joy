class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    ranges::sort(nums);
    vector<int> tmp(n);
    vector<int> st(n, 0);
    auto dfs = [&](auto &&dfs, int i) {
      if (i >= n) {
        res.push_back(tmp);
        return;
      }
      for (int j = 0; j < n; j++) {
        if (st[j]) {
          continue;
        }
        if (j >= 1 && nums[j] == nums[j - 1] && !st[j - 1]) {
          continue;
        }
        tmp[i] = nums[j];
        st[j]  = true;
        dfs(dfs, i + 1);
        st[j] = false;
      }
    };
    dfs(dfs, 0);
    return res;
  }
};
