class Solution {
 public:
  using LL = long long;
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    LL ans = 0;
    for (int i = 0;; i++) {
      LL c1 = (LL)cost1 * i;
      if (c1 > total) {
        break;
      }
      LL left = total - c1;
      int extra = left / cost2 + 1;
      ans += extra;
    }
    return ans;
  }
};
