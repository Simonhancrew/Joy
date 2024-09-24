class Solution {
public:
  using LL = long long;
  long long maximumSubsequenceCount(string text, string pattern) {
    LL cntx = 0, cnty = 0;
    LL ans = 0;
    for (const auto a : text) {
      if (a == pattern[1]) {
        ans += cntx;
        cnty++;
      }
      if (a == pattern[0]) {
        cntx++;
      }
    }
    return max(ans + cntx, ans + cnty);
  }
};
