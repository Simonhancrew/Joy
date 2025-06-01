class Solution {
 public:
  using LL = long long;
  long long distributeCandies(int n, int limit) {
    // [0, min(limit, n)], j, [0, n - i - j];
    // [max(0, n - i - limit), min(n - i, limit)]
    LL ans = 0;
    for (int i = 0; i <= min(limit, n); ++i) {
      int l = max(0, n - i - limit), r = min(n - i, limit);
      if (l > limit)
        continue;
      ans += (r - l + 1);
    }
    return ans;
  }
};
