#if 0
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      suf[i] = suf[i - 1] + nums[n - i];
    }
    int ans = INT_MAX;
    for (int i = 0; i <= (n + 1) / 2; i++) {
      int rhs = x - pre[i];
      if (rhs < 0) break;
      int j = lower_bound(suf.begin(), suf.end(), rhs) - suf.begin();
      if (i + j > n) break;
      if (suf[j] == rhs) ans = min(ans, i + j);
    }
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
#endif

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int lhs = 0, rhs = accumulate(nums.begin(), nums.end(), 0);
    if (rhs < x) return -1;
    int ans = INT_MAX, n = nums.size();
    for (int l = -1, r = 0; l < n; l++) {
      if (l != -1) {
        lhs += nums[l];
      }
      while (r < n && lhs + rhs > x) {
        rhs -= nums[r];
        r++;
      }
      if (lhs + rhs == x) {
        ans = min(ans, l + 1 + n - r);
      }
    }
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
