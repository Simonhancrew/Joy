class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    ranges::sort(nums);
    int n = nums.size();
    vector<int> f(n), to(n, n);
    auto dfs = [&](this auto &&dfs, int x) {
      int &res = f[x];
      if (res) {
        return res;
      }
      for (int i = x + 1; i < n; ++i) {
        if (nums[i] % nums[x] != 0) {
          continue;
        }
        int cur = dfs(i);
        if (cur > res) {
          res   = cur;
          to[x] = i;
        }
      }
      ++res;
      return res;
    };
    dfs(0);
    int max_res = 0, start = 0;
    for (int i = 0; i < n; i++) {
      auto res = dfs(i);
      if (res > max_res) {
        max_res = res;
        start   = i;
      }
    }
    vector<int> ans;
    for (int i = start; i < n; i = to[i]) {
      ans.push_back(nums[i]);
    }
    return ans;
  }
};
