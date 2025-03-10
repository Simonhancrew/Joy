class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  using LL                 = long long;
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    auto cp = nums1;
    ranges::sort(cp);
    int n   = nums1.size();
    int sum = 0;
    int tar = 0;
    for (int i = 0; i < n; i++) {
      if (nums1[i] == nums2[i]) {
        continue;
      }
      int cur = abs(nums1[i] - nums2[i]);
      sum     = (sum + cur) % MOD;
      int l = -1, r = n;
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (cp[mid] <= nums2[i])
          l = mid;
        else
          r = mid;
      }
      int sub = INT_MAX;
      if (l != -1)
        sub = min(sub, abs(cp[l] - nums2[i]));
      if (r != n)
        sub = min(sub, abs(cp[r] - nums2[i]));
      if (sub < cur)
        tar = max(tar, cur - sub);
    }
    return (sum - tar + MOD) % MOD;
  }
};
