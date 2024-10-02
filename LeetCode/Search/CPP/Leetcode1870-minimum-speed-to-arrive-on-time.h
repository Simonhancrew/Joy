class Solution {
public:
  using LL = long long;
  int minSpeedOnTime(vector<int> &dist, double hour) {
    LL acc = accumulate(dist.begin(), dist.end(), 0ll);
    int l = (acc + hour - 1) / hour - 1, r = 1e7 + 1;
    int n = dist.size();
    auto check = [&](int e) {
      LL ans = 0;
      for (int i = 0; i < n - 1; i++) {
        ans += (dist[i] + e - 1) / e;
      }
      auto f = static_cast<double>(ans) +
               static_cast<double>(dist[n - 1]) / static_cast<double>(e);
      return f <= hour;
    };
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    if (r == 1e7 + 1)
      return -1;
    return r;
  }
};
