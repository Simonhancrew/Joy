class Solution {
 public:
  using LL = long long;
  int maxValue(int n, int index, int maxSum) {
    int l = 1, r = maxSum;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid, n, index, maxSum))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }

  LL calcu(int mx, int len) {
    if (len + 1 < mx) {
      int mn = mx - len;
      return (LL)(mx - 1 + mn) * len / 2;
    } else {
      int cnt = len - mx + 1;
      return (LL)(mx - 1) * mx / 2 + cnt;
    }
  }

  bool check(int tar, int n, int index, int maxSum) {
    int lhs_len = index, rhs_len = n - 1 - index;
    return tar + calcu(tar, lhs_len) + calcu(tar, rhs_len) <= maxSum;
  }
};