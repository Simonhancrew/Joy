class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    if (nums.size() == 1) {
      return false;
    }
    ranges::sort(nums, [](int l, int r) {
      return l > r;
    });
    auto total = accumulate(nums.begin(), nums.end(), 0);
    if (total & 1)
      return false;
    int n = nums.size();
    vector<vector<int>> f(n, vector<int>(total / 2 + 1, -1));
    auto dfs = [&](this auto &&dfs, int i, int j) -> bool {
      if (i >= n) {
        return j == 0;
      }
      int &res = f[i][j];
      if (res != -1) {
        return res;
      }
      return res = j >= nums[i] && dfs(i + 1, j - nums[i]) || dfs(i + 1, j);
    };
    return dfs(0, total / 2);
  }
};
