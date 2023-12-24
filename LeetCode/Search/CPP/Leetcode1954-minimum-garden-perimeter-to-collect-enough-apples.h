class Solution {
 public:
  using LL = long long;
  long long minimumPerimeter(long long neededApples) {
    LL l = 0, r = 1e5 + 10;
    auto calcu = [](LL n) { return 2 * n * (n + 1) * (2 * n + 1); };
    while (l + 1 < r) {
      LL mid = l + r >> 1;
      if (calcu(mid) >= neededApples)
        r = mid;
      else
        l = mid;
    }
    return 8 * r;
  }
};
