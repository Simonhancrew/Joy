class Solution {
public:
  using LL = long long;
  long long minimumTime(vector<int> &time, int totalTrips) {
    LL mn_time = *min_element(time.begin(), time.end());
    LL l = 0, r = mn_time * totalTrips + 1;
    auto check = [&time, totalTrips](LL t) {
      LL acc = 0;
      for (const auto x : time) {
        acc += t / x;
      }
      return acc >= totalTrips;
    };
    while (l + 1 < r) {
      LL mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    return r;
  }
};
