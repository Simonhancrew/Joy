class Solution {
 public:
  int mx{INT_MIN}, mn{INT_MAX};
  void Get(const vector<int>& nums) {
    for (const auto& x : nums) {
      if (x >= mx) mx = x;
      if (x <= mn) mn = x;
    }
  }

  int longestArithSeqLength(vector<int>& nums) {
    Get(nums);
    int res = 2, n = nums.size();
    vector<vector<int>> f(n, vector<int>(2 * (mx - mn) + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int diff = nums[i] - nums[j] + mx - mn;
        f[i][diff] = max(f[i][diff], 2);
        f[i][diff] = max(f[i][diff], f[j][diff] + 1);
        res = max(res, f[i][diff]);
      }
    }
    return res;
  }
};
