#include <vector>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long repairCars(vector<int>& ranks, int cars) {
    LL l = 1, r = 1e16;
    auto check = [cars, &ranks](LL mid) {
      LL cnt = 0;
      for (const auto r : ranks) {
        cnt += static_cast<LL>(sqrt(mid / r));
        if (cnt >= cars) {
          return true;
        }
      }
      return false;
    };
    while (l < r) {
      auto mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};
