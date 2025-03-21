class Solution {
 public:
  using LL = long long;
  vector<LL> suf;
  long long maximumOr(vector<int> &nums, int k) {
    int n = nums.size();
    suf.resize(n);
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1] | nums[i + 1];
    }
    LL ans = -1, pre = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, pre | ((LL)nums[i] << k) | suf[i]);
      pre |= nums[i];
    }
    return ans;
  }
};
