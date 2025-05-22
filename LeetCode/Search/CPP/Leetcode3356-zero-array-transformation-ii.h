class Solution {
 public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int l = -1, r = queries.size() + 1;
    int n      = nums.size();
    auto check = [&](int x) {
      vector<int> pre(n + 1, 0);
      for (int i = 0; i < x; i++) {
        auto &q = queries[i];
        pre[q[0]] += q[2];
        pre[q[1] + 1] -= q[2];
      }
      for (int i = 0; i < n; i++) {
        pre[i] += (i > 0 ? pre[i - 1] : 0);
        if (pre[i] < nums[i]) {
          return false;
        }
      }
      return true;
    };
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    if (r > queries.size()) {
      return -1;
    }
    return r;
  }
};
